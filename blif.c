
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


int my_simulate(network_t** network, const char *blif_fname, 
                    const char *bool_str, char *outputs_line)
{
    FILE* blif = fopen(blif_fname, "r");
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



    //int num_po = network_num_po(*network);
    //printf("Number of outputs in scheme %d\n", num_po);



    for (int i = 0; i < num_values; ++i) {
        if (!bool_str[i]) {
            puts("too few input values :(");
            goto bail;
        }
        array_insert_last(int, values, bool_str[i] - '0');
    }

    array_t* outs = simulate_network(*network, nodes, values);
    if (!outs) {
        puts("simulate network failed :(");
        goto bail;
    }

    for (int i = 0; i < outs->num; ++i)
    {
        //printf("out[%d] = %d\n", i, array_fetch(int, outs, i));
        int o = array_fetch(int, outs, i);
        printf("out[%d] = %d\n", i, o);
        outputs_line[i] = o + '0';
    }

bail:
    array_free(outs);
    array_free(values);
    array_free(nodes);

    return 0;
}








//int test_from_file(const char *input_fname, const char *output_fname)
//blif-файл, pla-файл с входными наборами, файл с выходными наборами
int test_from_file(network_t** network, int argc, const char* argv[])
{

    if (argc < 4) {
        puts("too few arguments :(");
        return -1;
    }

    puts(argv[1]);
    puts(argv[2]);






    FILE* inputs_file = fopen(argv[2], "r");
    if (!inputs_file) {
        perror("no file of inputs or no permissions :(");
        return -5;
    }

//
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

    int num_pi = network_num_pi(*network);
    printf("Number of inputs in scheme %d\n", num_pi);

    int num_po = network_num_po(*network);
    printf("Number of outputs in scheme %d\n", num_po);

    fclose(blif);

    //

    char line[1024]; //вот тут может поломаться
                        //из-за размера буффера (если число входов больше 1024)

    char outputs_line[1024]; //выходные значения - и тут может поломаться :)


    int num_inputs = 0, num_outputs = 0, num_rows = 0;

    //int num_values = network_num_pi(*network);
    //printf("Number of inputs in scheme %d\n", num_values);



    FILE* outputs_file = fopen(argv[3], "w");
    if (!outputs_file) {
        perror("no file of outputs or no permissions :(");
        return -2;
    }




    while((fgets(line, sizeof(line), inputs_file)) != NULL)
    {
        printf("%s", line);

        if (line[0] == '.')
        {
            if (strstr(line, ".i") == line)
            {
                sscanf(line, ".i %d", &num_inputs);

                if (num_inputs != num_pi)
                {
                    perror("incorrect PLA :(");
                    return -4;
                }

                fprintf(outputs_file, "i. %d\n", num_pi);
                fprintf(outputs_file, "o. %d\n", num_po);
                
            }
            else if (strstr(line, ".o") == line)
            {
                sscanf(line, ".o %d", &num_outputs);
            }
            else if (strstr(line, ".p") == line)
            {
                sscanf(line, ".p %d", &num_rows);

                fprintf(outputs_file, "p. %d\n", num_rows);
            }
        }


        if (line[0] == '0' || line[0] == '1')
        {
            //printf("%d", strlen(line));
            
            //допустима запись outputs через пробел,
            //хотя зачем мне в такой постновке задачи вообще выходы и пробелы?
            if ((strlen(line) != num_inputs + num_outputs + 1) 
                    && (strlen(line) != num_inputs + num_outputs + 2)) 
            {
                perror("incorrect PLA :(");
                return -4;
            }

            my_simulate(network, argv[1], line, outputs_line);
            //printf("\n%d", strlen(outputs_line));
            //printf("\n%s", outputs_line);

            //fputs(line, outputs_file);
            //fprintf(outputs_file, "%c", " ");
            for(int i = 0; i < num_po; ++i)
            {
                 //fprintf(outputs_file, "%c", outputs_line[i]);
            }
            //fprintf(outputs_file, "%c", "\n");
            //fputs("\n", outputs_file);


            for(int i = 0; i < num_pi; ++i)
            {
                 fprintf(outputs_file, "%c", line[i]);
            }

            fprintf(outputs_file, "%c", ' ');

            for(int i = 0; i < num_po; ++i)
            {
                 fprintf(outputs_file, "%c", outputs_line[i]);
            }

            fprintf(outputs_file, "%c", '\n');

        }

        /*
        for (int i = 0; i < num_values; ++i) {
        
            //printf("%c", line[i]);
            printf("\ni = %d", i);

            array_insert_last(int, values, line[i] - '0');
        
        }*/
        
    }



    fclose(outputs_file);



    
}








//имя blif-файла, булева строка
int mytest(network_t** network, int argc, const char* argv[]) {

    
    puts("Here");
    printf("%d", strlen(argv[2]));



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
    com_add_command("my_read_blif_from_file", test_from_file, 1);
    
    return 0;
}

int end_test()
{
    return 0;
}
