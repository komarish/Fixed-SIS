
#include <stdio.h>
#include <sis/ansi.h>
#include <sis/array.h>
#include <sis/list.h>
#include <sis/st.h>
#include <sis/espresso.h>
#include <sis/node.h>
#include <sis/network.h>
#include <sis/io.h>

#include <sis/command.h>


extern array_t* simulate_network();

#define array_data_(x, y) (array_data(x, y))

int mytest(network_t** network, int argc, const char* argv[]) {
    if (argc < 3) {
        puts("too few arguments :(");
        return -1;
    }
    
    puts(argv[1]);

    FILE* blif = fopen(argv[1], "r");
    if (!blif) {
        perror("no file or no permissions :(");
        return -2;
    }

    int err = read_blif(blif, network);
    if (!err) {
        puts("read_blif failed :(");
        return -3;
    }

    array_t* nodes = network_dfs(*network);
    if (!nodes) {
        puts("network_dfs failed :(");
        return -4;
    }

    int num_values = network_num_pi(*network);
    printf("Number of inputs in scheme %d\n", num_values);
    array_t* values = array_alloc(int, num_values);
    if (!values) {
        puts("array alloc failed :(");
        goto bail;
    }


    for (int i = 0; i < num_values; ++i) {
        if (!argv[2][i]) {
            puts("too few input values :(");
            goto bail;
        }
        array_insert_last(int, values, argv[2][i] - '0');
    }

    array_t* outs = simulate_network(*network, nodes, values);
    if (!outs) {
        puts("simulate network failed :(");
        goto bail;
    }

    for (int i = 0; i < outs->num; ++i)
        //printf("out[%d] = %d\n", i, array_fetch(int, outs, i));
        printf("out[%d] = %d\n", i, array_fetch(int, outs, i));

bail:
    array_free(outs);
    array_free(values);
    array_free(nodes);

    return err;
}

int init_test()
{
    com_add_command("my_read_blif", mytest, 1);
    return 0;
}

int end_test()
{
    return 0;
}
