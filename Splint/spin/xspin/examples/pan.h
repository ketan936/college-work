#define Version	"Spin Version 4.3.0 -- 22 June 2007"
#define Source	"pan_in"

char *TrailFile = Source; /* default */
#if defined(BFS)
#ifndef SAFETY
#define SAFETY
#endif
#ifndef XUSAFE
#define XUSAFE
#endif
#endif
#ifndef uchar
#define uchar	unsigned char
#endif
#ifndef uint
#define uint	unsigned int
#endif
#define DELTA	500
#ifdef MA
#if MA==1
#undef MA
#define MA	100
#endif
#endif
#ifdef W_XPT
#if W_XPT==1
#undef W_XPT
#define W_XPT 1000000
#endif
#endif
#ifndef NFAIR
#define NFAIR	2	/* must be >= 2 */
#endif
#define HAS_CODE
#define MERGED	1
#ifdef NP	/* includes np_ demon */
#define HAS_NP	2
#define VERI	2
#define endclaim	3 /* none */
#endif
typedef struct S_F_MAP {
	char *fnm; int from; int upto;
} S_F_MAP;

#define nstates1	12	/* :init: */
#define endstate1	11
short src_ln1 [] = {
	  0,  75,  77,  78,  79,  80,  81,  76, 
	 83,  76,  74,  84,   0, };
S_F_MAP src_file1 [] = {
	{ "-", 0, 0 },
	{ "pan_in", 1, 11 },
	{ "-", 12, 13 }
};
uchar reached1 [] = {
	  0,   1,   1,   0,   0,   1,   1,   0, 
	  1,   1,   0,   0,   0, };

#define nstates0	50	/* node */
#define endstate0	49
short src_ln0 [] = {
	  0,  22,  23,  25,  27,  29,  30,  31, 
	 32,  34,  35,  36,  28,  38,  38,  39, 
	 26,  42,  42,  44,  46,  47,  48,  49, 
	 50,  45,  52,  52,  53,  43,  55,  55, 
	 57,  58,  59,  60,  61,  62,  56,  64, 
	 65,  66,  66,  64,  68,  68,  24,  70, 
	 24,  70,   0, };
S_F_MAP src_file0 [] = {
	{ "-", 0, 0 },
	{ "pan_in", 1, 49 },
	{ "-", 50, 51 }
};
uchar reached0 [] = {
	  0,   0,   0,   1,   1,   1,   0,   0, 
	  1,   0,   0,   0,   0,   1,   1,   0, 
	  0,   1,   1,   1,   1,   0,   0,   1, 
	  0,   0,   1,   1,   0,   0,   1,   1, 
	  1,   0,   1,   0,   0,   0,   0,   1, 
	  1,   1,   0,   0,   1,   1,   0,   1, 
	  1,   0,   0, };
struct {
	int tp; short *src;
} src_all[] = {
	{ 1, &src_ln1[0] },
	{ 0, &src_ln0[0] },
	{ 0, (short *) 0 }
};
short *frm_st0;
struct {
	char *c; char *t;
} code_lookup[] = {
	{ (char *) 0, "" }
};
#define _T5	29
#define _T2	30
#define SYNC	0
#define ASYNC	1

char *procname[] = {
   "node",
   ":init:",
   ":np_:",
};

#define Pinit	((P1 *)this)
typedef struct P1 { /* :init: */
	unsigned _pid : 8;  /* 0..255 */
	unsigned _t   : 3; /* proctype */
	unsigned _p   : 7; /* state    */
	uchar proc;
} P1;
#define Air1	(sizeof(P1) - Offsetof(P1, proc) - 1*sizeof(uchar))
#define Pnode	((P0 *)this)
typedef struct P0 { /* node */
	unsigned _pid : 8;  /* 0..255 */
	unsigned _t   : 3; /* proctype */
	unsigned _p   : 7; /* state    */
	unsigned Active : 1;
	unsigned know_winner : 1;
	uchar mynumber;
	uchar nr;
	uchar maximum;
	uchar neighbourR;
	uchar in;
	uchar out;
} P0;
#define Air0	(sizeof(P0) - Offsetof(P0, out) - 1*sizeof(uchar))
typedef struct P2 { /* np_ */
	unsigned _pid : 8;  /* 0..255 */
	unsigned _t   : 3; /* proctype */
	unsigned _p   : 7; /* state    */
} P2;
#define Air2	(sizeof(P2) - 3)
#if defined(BFS) && defined(REACH)
#undef REACH
#endif
#ifdef VERI
#define BASE	1
#else
#define BASE	0
#endif
typedef struct Trans {
	short atom;	/* if &2 = atomic trans; if &8 local */
#ifdef HAS_UNLESS
	short escp[HAS_UNLESS];	/* lists the escape states */
	short e_trans;	/* if set, this is an escp-trans */
#endif
	short tpe[2];	/* class of operation (for reduction) */
	short qu[6];	/* for conditional selections: qid's  */
	uchar ty[6];	/* ditto: type's */
#ifdef NIBIS
	short om;	/* completion status of preselects */
#endif
	char *tp;	/* src txt of statement */
	int st;		/* the nextstate */
	int t_id;	/* transition id, unique within proc */
	int forw;	/* index forward transition */
	int back;	/* index return  transition */
	struct Trans *nxt;
} Trans;

#define qptr(x)	(((uchar *)&now)+(int)q_offset[x])
#define pptr(x)	(((uchar *)&now)+(int)proc_offset[x])
extern uchar *Pptr(int);
#define q_sz(x)	(((Q0 *)qptr(x))->Qlen)

#ifndef VECTORSZ
#define VECTORSZ	1024           /* sv   size in bytes */
#endif

#ifdef VERBOSE
#ifndef CHECK
#define CHECK
#endif
#ifndef DEBUG
#define DEBUG
#endif
#endif
#ifdef SAFETY
#ifndef NOFAIR
#define NOFAIR
#endif
#endif
#ifdef NOREDUCE
#ifndef XUSAFE
#define XUSAFE
#endif
#if !defined(SAFETY) && !defined(MA)
#define FULLSTACK
#endif
#else
#ifdef BITSTATE
#ifdef SAFETY && !defined(HASH64)
#define CNTRSTACK
#else
#define FULLSTACK
#endif
#else
#define FULLSTACK
#endif
#endif
#ifdef BITSTATE
#ifndef NOCOMP
#define NOCOMP
#endif
#if !defined(LC) && defined(SC)
#define LC
#endif
#endif
#if defined(COLLAPSE2) || defined(COLLAPSE3) || defined(COLLAPSE4)
/* accept the above for backward compatibility */
#define COLLAPSE
#endif
#ifdef HC
#undef HC
#define HC4
#endif
#ifdef HC0
#define HC	0
#endif
#ifdef HC1
#define HC	1
#endif
#ifdef HC2
#define HC	2
#endif
#ifdef HC3
#define HC	3
#endif
#ifdef HC4
#define HC	4
#endif
#ifdef COLLAPSE
unsigned long ncomps[256+2];
#endif
#define MAXQ   	255
#define MAXPROC	255
#define WS		sizeof(long)   /* word size in bytes */
typedef struct Stack  {	 /* for queues and processes */
#if VECTORSZ>32000
	int o_delta;
	int o_offset;
	int o_skip;
	int o_delqs;
#else
	short o_delta;
	short o_offset;
	short o_skip;
	short o_delqs;
#endif
	short o_boq;
#ifndef XUSAFE
	char *o_name;
#endif
	char *body;
	struct Stack *nxt;
	struct Stack *lst;
} Stack;

typedef struct Svtack { /* for complete state vector */
#if VECTORSZ>32000
	int o_delta;
	int m_delta;
#else
	short o_delta;	 /* current size of frame */
	short m_delta;	 /* maximum size of frame */
#endif
#if SYNC
	short o_boq;
#endif
	char *body;
	struct Svtack *nxt;
	struct Svtack *lst;
} Svtack;

Trans ***trans;	/* 1 ptr per state per proctype */

#if defined(FULLSTACK) || defined(BFS)
struct H_el *Lstate;
#endif
int depthfound = -1;	/* loop detection */
#if VECTORSZ>32000
int proc_offset[MAXPROC];
int q_offset[MAXQ];
#else
short proc_offset[MAXPROC];
short q_offset[MAXQ];
#endif
uchar proc_skip[MAXPROC];
uchar q_skip[MAXQ];
unsigned long  vsize;	/* vector size in bytes */
#ifdef SVDUMP
int vprefix=0, svfd;		/* runtime option -pN */
#endif
char *tprefix = "trail";	/* runtime option -tsuffix */
short boq = -1;		/* blocked_on_queue status */
typedef struct State {
	uchar _nr_pr;
	uchar _nr_qs;
	uchar   _a_t;	/* cycle detection */
#ifndef NOFAIR
	uchar   _cnt[NFAIR];	/* counters, weak fairness */
#endif
#ifndef NOVSZ
#if VECTORSZ<65536
	unsigned short _vsz;
#else
	unsigned long  _vsz;
#endif
#endif
#ifdef HAS_LAST
	uchar  _last;	/* pid executed in last step */
#endif
#ifdef EVENT_TRACE
#if nstates_event<256
	uchar _event;
#else
	unsigned short _event;
#endif
#endif
	uchar nr_leaders;
	uchar q[5];
	uchar sv[VECTORSZ];
} State;

#define HAS_TRACK	0
int _; /* a predefined write-only variable */

#define FORWARD_MOVES	"pan.m"
#define REVERSE_MOVES	"pan.b"
#define TRANSITIONS	"pan.t"
#define _NP_	2
uchar reached2[3];  /* np_ */
#define nstates2	3 /* np_ */
#define endstate2	2 /* np_ */

#define start2	0 /* np_ */
#define start1	10
#define start0	1
#ifdef NP
#define ACCEPT_LAB	1 /* at least 1 in np_ */
#else
#define ACCEPT_LAB	0 /* user-defined accept labels */
#endif
#define PROG_LAB	0 /* progress labels */
uchar *accpstate[3];
uchar *progstate[3];
uchar *reached[3];
uchar *stopstate[3];
uchar *visstate[3];
short *mapstate[3];
#ifdef HAS_CODE
int NrStates[3];
#endif
#define NQS	5
short q_flds[6];
short q_max[6];
typedef struct Q5 {
	uchar Qlen;	/* q_size */
	uchar _t;	/* q_type */
	struct {
		uchar fld0;
		uchar fld1;
	} contents[10];
} Q5;
typedef struct Q4 {
	uchar Qlen;	/* q_size */
	uchar _t;	/* q_type */
	struct {
		uchar fld0;
		uchar fld1;
	} contents[10];
} Q4;
typedef struct Q3 {
	uchar Qlen;	/* q_size */
	uchar _t;	/* q_type */
	struct {
		uchar fld0;
		uchar fld1;
	} contents[10];
} Q3;
typedef struct Q2 {
	uchar Qlen;	/* q_size */
	uchar _t;	/* q_type */
	struct {
		uchar fld0;
		uchar fld1;
	} contents[10];
} Q2;
typedef struct Q1 {
	uchar Qlen;	/* q_size */
	uchar _t;	/* q_type */
	struct {
		uchar fld0;
		uchar fld1;
	} contents[10];
} Q1;
typedef struct Q0 {	/* generic q */
	uchar Qlen;	/* q_size */
	uchar _t;
} Q0;

/** function prototypes **/
char *emalloc(unsigned long);
char *Malloc(unsigned long);
int Boundcheck(int, int, int, int, Trans *);
int addqueue(int, int);
/* int atoi(char *); */
/* int abort(void); */
int close(int);
int delproc(int, int);
int endstate(void);
int hstore(char *, int);
#ifdef MA
int gstore(char *, int, uchar);
#endif
int q_cond(short, Trans *);
int q_full(int);
int q_len(int);
int q_zero(int);
int qrecv(int, int, int, int);
int unsend(int);
/* void *sbrk(int); */
void Uerror(char *);
void assert(int, char *, int, int, Trans *);
void c_chandump(int);
void c_globals(void);
void c_locals(int, int);
void checkcycles(void);
void crack(int, int, Trans *, short *);
void d_hash(uchar *, int);
void s_hash(uchar *, int);
void r_hash(uchar *, int);
void delq(int);
void do_reach(void);
void pan_exit(int);
void exit(int);
void hinit(void);
void imed(Trans *, int, int, int);
void new_state(void);
void p_restor(int);
void putpeg(int, int);
void putrail(void);
void q_restor(void);
void retrans(int, int, int, short *, uchar *);
void settable(void);
void setq_claim(int, int, char *, int, char *);
void sv_restor(void);
void sv_save(void);
void tagtable(int, int, int, short *, uchar *);
void uerror(char *);
void unrecv(int, int, int, int, int);
void usage(FILE *);
void wrap_stats(void);
#if defined(FULLSTACK) && defined(BITSTATE)
int  onstack_now(void);
void onstack_init(void);
void onstack_put(void);
void onstack_zap(void);
#endif
#ifndef XUSAFE
int q_S_check(int, int);
int q_R_check(int, int);
uchar q_claim[MAXQ+1];
char *q_name[MAXQ+1];
char *p_name[MAXPROC+1];
#endif
void qsend(int, int, int, int);
#define Addproc(x)	addproc(x, 0, 0, 0)
#define LOCAL	1
#define Q_FULL_F	2
#define Q_EMPT_F	3
#define Q_EMPT_T	4
#define Q_FULL_T	5
#define TIMEOUT_F	6
#define GLOBAL	7
#define BAD	8
#define ALPHA_F	9
#define NTRANS	31
#ifdef PEG
long peg[NTRANS];
#endif
