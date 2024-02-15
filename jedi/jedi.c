
/*
 * Symbolic encoding program for compiling a symbolic
 * description into a binary representation.  Target
 * is multi-level logic synthesis
 *
 * History:
 *
 * Bill Lin
 * University of California, Berkeley
 * Comments to billlin@ic.Berkeley.EDU
 *
 * Copyright (c) 1989 Bill Lin, UC Berkeley CAD Group
 *     Permission is granted to do anything with this
 *     code except sell it or remove this message.
 */

#include "jedi.h"

FILE *infp;			/* input file pointer */
FILE *outfp;			/* output file pointer */

main(argc, argv)
int argc;
char **argv;
{
    /*
     * parse options
     */
    parse_options(argc, argv);

    /*
     * read input from stdin
     */
    if (kissFlag) {
	read_kiss(infp, outfp);
    } else {
	read_input(infp, outfp);
    }

    /*
     * check if one hot
     */
    if (hotFlag) {
	write_one_hot(outfp);
	(void) exit(0);
    }

    /*
     * compute weights
     */
    if (!sequentialFlag && !srandomFlag && !drandomFlag) {
	compute_weights();
    }

    /* 
     * solve the embedding problem 
     */
    if (srandomFlag || drandomFlag) {
	random_embedding();
    } else if (clusterFlag) {
	cluster_embedding();
    } else if (!sequentialFlag) {
	opt_embedding();			
    }

    if (kissFlag && !plaFlag) {
	write_blif(outfp);
    } else if (kissFlag && plaFlag) {
	write_output(outfp);			
    } else {
	write_output(outfp);			
    }

    (void) exit(0);
} /* end of main */



/*
 * flags
 */
Boolean addDontCareFlag;	/* fully specify the machine */
Boolean bitsFlag;		/* specify a kiss-style input */
Boolean kissFlag;		/* specify a kiss-style input */
Boolean verboseFlag;		/* display verbose information */
Boolean sequentialFlag;		/* run sequential encoding */
Boolean clusterFlag;		/* run cluster encoding */
Boolean srandomFlag;		/* run static random */
Boolean drandomFlag;		/* run dynamic random */
Boolean variationFlag;		/* variation of weight calculation */
Boolean oneplaneFlag;		/* compute weights only on one plane */
Boolean hotFlag;		/* one hot encoding */
Boolean expandFlag;		/* code expansion flag */
Boolean plaFlag;		/* output PLA format */

/*
 * parameters
 */
double beginningStates;		/* number of beginning states for SA */
double endingStates;		/* number of ending states for SA */
double startingTemperature;	/* starting temperature for SA */
double maximumTemperature;	/* maximum temperature for SA */
int weightType;			/* options for weighting type */

char *reset_state;		/* reset state for state assignment */
int code_length;		/* code length for state assignemnt */


int ni;				/* number of inputs */
int no;				/* number of outputs */
int np;				/* number of symbolic product terms */
int ne;				/* number of enumtype types */
int tni;			/* total number of binary inputs */
int tno;			/* total number of binary outputs */
struct Enumtype *enumtypes;	/* array of enumtypes */
struct Variable *inputs;	/* array of inputs */
struct Variable *outputs;	/* array of outputs */
