#include <stdio.h>
#include <string.h>

enum WRTK_RET_ {
	WRTK_RET_OK,
	WRTK_RET_UNEXPECTED_STATE,
	WRTK_RET_ARGINVAL,
	WRTK_RET_FILE_NOFOUND
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
		ST_FOUND_EXTRN,
		ST_IDLE_FOREVER
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

				if(ST != ST_FOUND_EXTRN) {
					char STR[] = KEY_EXTERN;
					STR[GETEXTERN.m_num_read - 1] =
						GETEXTERN.m_lastread != EOF ? GETEXTERN.m_lastread : '\0';

					STR[GETEXTERN.m_num_read] = '\0';

					fputs(STR, fo);
				}
			} break;

		case ST_FOUND_EXTRN:
			{
				wrtk_chr_t	c;
				while(((c = fgetc(fi)) != '}') && c != EOF);
				ST = c == EOF ? ST_END : ST_IDLE_FOREVER;
			} break;

		case ST_IDLE_FOREVER:
			{
				wrtk_chr_t	c;
				while((c = fgetc(fi)) != EOF && fputc(c, fo));
				ST = ST_END;
			} break;
	}

L_END:
	return WRTK_RET_OK;
}

int main(int argc, const char** argv) {
	FILE *fi, *fo;
	enum WRTK_RET_	R;

	if(argc != 3) return WRTK_RET_ARGINVAL;


	fi = fopen(argv[1], "r");
	fo = strcmp(argv[2], argv[1]) ? fopen(argv[2], "w") : tmpfile();

	if(!(fi && fo)) return WRTK_RET_FILE_NOFOUND;

	R = wrtk_run(fi, fo);

	fclose(fi);

	if(!strcmp(argv[2], argv[1])) {
		wrtk_chr_t ch;
		fi = fopen(argv[1], "w");
		fseek(fo, 0, SEEK_SET);

		while ((ch = fgetc(fo)) != EOF) {
			fputc(ch, fi);
		}

		fclose(fi);
	}

	fclose(fo);

	return R;
}
