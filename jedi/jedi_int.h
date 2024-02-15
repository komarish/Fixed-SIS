
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

/*
 * constants
 */
#define INFINITY 100000		/* constant for infinity */
#define BUFSIZE 512		/* buffer size */
#define INPUT 0			/* input weighting */
#define OUTPUT 1		/* output weighting */
#define COUPLED 2		/* coupled weighting */
#define MAXSPACE 8		/* maximum Boolean dimensions */

#define RELEASE "official release 1.2"
#define DATE "June 5, 1991"
#define HEADER "JEDI, official release 1.2 (compiled: June 5, 1991)"

/*
 * flags
 */
extern Boolean addDontCareFlag;	/* fully specify the machine */
extern Boolean bitsFlag;		/* specify a kiss-style input */
extern Boolean kissFlag;		/* specify a kiss-style input */
extern Boolean verboseFlag;		/* display verbose information */
extern Boolean sequentialFlag;		/* run sequential encoding */
extern Boolean clusterFlag;		/* run cluster encoding */
extern Boolean srandomFlag;		/* run static random */
extern Boolean drandomFlag;		/* run dynamic random */
extern Boolean variationFlag;		/* variation of weight calculation */
extern Boolean oneplaneFlag;		/* compute weights only on one plane */
extern Boolean hotFlag;		/* one hot encoding */
extern Boolean expandFlag;		/* code expansion flag */
extern Boolean plaFlag;		/* output PLA format */

/*
 * parameters
 */
extern double beginningStates;		/* number of beginning states for SA */
extern double endingStates;		/* number of ending states for SA */
extern double startingTemperature;	/* starting temperature for SA */
extern double maximumTemperature;	/* maximum temperature for SA */
extern int weightType;			/* options for weighting type */

extern char *reset_state;		/* reset state for state assignment */
extern int code_length;		/* code length for state assignemnt */
