#include <stdio.h>

enum WRTK_RET_ {
	WRTK_RET_OK,
	WRTK_RET_UNEXPECTED_STATE
};

#define	KEY_EXTERN	"extern \"C\""

#define	lstrlen(A)	(sizeof(A) - 1u)

typedef int wrtk_chr_t;

struct KVIEW {
	unsigned		m_num_read;
	wrtk_chr_t		m_lastread;
};

struct KVIEW s_wrtk_get_extern(FILE* fi) {
	struct KVIEW	R;
	unsigned		i = 0;
	wrtk_chr_t		c;

	while(i < lstrlen(KEY_EXTERN) && (c = fgetc(fi)) == KEY_EXTERN[i++]);
	R.m_num_read = i;
	R.m_lastread = c;

	return R;
}

enum WRTK_RET_ wrtk_run(FILE* fi, FILE* fo) {
	enum {
		ST_END,
		ST_IDLE,
		ST_FOUND_EXTRN
	} ST;
	ST = ST_IDLE;

	while(ST) switch(ST) {
		default:
			return WRTK_RET_UNEXPECTED_STATE;
		case ST_END:
			goto L_END;
		case ST_IDLE:
			{
				struct KVIEW GETEXTERN = s_wrtk_get_extern(fi);
				ST = GETEXTERN.m_lastread == EOF ? ST_END : ST;
				ST = GETEXTERN.m_num_read == lstrlen(KEY_EXTERN) && GETEXTERN.m_lastread == '\"'
					? ST_FOUND_EXTRN : ST;

				if(ST == ST_IDLE) {
					fwrite(KEY_EXTERN, 1, GETEXTERN.m_num_read - 1, fo);
					fputc(GETEXTERN.m_lastread, fo);
				}
			} break;

		case ST_FOUND_EXTRN:
			{
				wrtk_chr_t	c;
				while(((c = fgetc(fi)) != '}') && ((c = fgetc(fi)) != EOF));
				fputc(c, fo);
				ST = c == EOF ? ST_END : ST_IDLE;
			} break;
	}

L_END:
	return WRTK_RET_OK;
}

int main(int argc, const char** argv) {
	FILE *fi, *fo;
	if(argc != 3) return -1;

	fi = fopen(argv[1], "r");
	fo = fopen(argv[2], "w");

	fi = fi ? fi : stdin;
	fo = fo ? fo : stdout;

	return (int)wrtk_run(fi, fo);
}
