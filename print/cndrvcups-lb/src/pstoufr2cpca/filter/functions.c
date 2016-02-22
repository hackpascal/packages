#include <cups/cups.h>
#include <cups/ppd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "functions.h"

#define	SEPARATOR						","
#define	PPD_KEY_CNGSADDITIONALOPTIONS	"*CNGSAdditionalOptions:"
#define	REAR_ARGUMENT					"-"
#define PPD_KEY_SPACE_LEN 1

static char *get_gs_option(char *string, char **next);
static void free_gs_cmd_arg(char **cmd_arg, int arraycnt);
static char* get_ppd_value(char* pKey);

static
char *get_gs_option(char *string, char **next)
{
	char *gs_option = NULL;
	
	if ((string != NULL) && (next != NULL)) {
		
		char *tmpstr = NULL;
		tmpstr = strtok_r(string, SEPARATOR, next);
		if (tmpstr != NULL) {
			gs_option = strdup(tmpstr);
		}
	}
	
	return gs_option;
}

static
void free_gs_cmd_arg(char **cmd_arg, int arraycnt)
{
	if (cmd_arg != NULL) {
		int i = 0;
		
		for(i = 0 ; i < arraycnt ; i++)
		{
			if (cmd_arg[i] != NULL) {
				free(cmd_arg[i]);
				cmd_arg[i] = NULL;
			}
		}
		free(cmd_arg);
	}
}

static
char* get_ppd_value(char* pKey)
{
	char	*pValue = NULL;

	if (pKey != NULL) {
		FILE	*fp = NULL;
		char	*p_ppd_name = getenv("PPD");

		if (p_ppd_name != NULL) {
			fp = fopen(p_ppd_name, "r");
			if (fp != NULL) {
				char	line_buf[LINE_BUF_SIZE];

				while (fgets(line_buf, sizeof(line_buf), fp)) {
					if (strncmp(line_buf, pKey, strlen(pKey)) == 0) {
						pValue = (char*)calloc((size_t)BUFSIZE, sizeof(char));
						if (pValue != NULL) {
							(void)GetValue((line_buf + PPD_KEY_SPACE_LEN + (int)strlen(pKey)), pValue, BUFSIZE);
						}
						break;
					}
				}
				fclose(fp);
			}
		}
	}
	return pValue;
}

char **init_cmd_arg(char *org_arg[], int org_arg_cnt, int *cmd_arg_num)
{
	char **cmd_arg = NULL;
	int add_arg_cnt = 0;
	bool success = true;
	char *ppdvalue = NULL;
	
	if (org_arg == NULL) {
		success = false;
	}
	
	if (success != false) {
		ppdvalue = get_ppd_value( PPD_KEY_CNGSADDITIONALOPTIONS );

		if ( ppdvalue != NULL ) {
			char *tmpstr = NULL;
				
			add_arg_cnt = add_arg_cnt + 1;
			tmpstr = strstr(ppdvalue, SEPARATOR);
			
			while (tmpstr != NULL) {
				add_arg_cnt = add_arg_cnt + 1;
				tmpstr = tmpstr + 1;
				tmpstr = strstr(tmpstr, SEPARATOR);
			}
		}	
	}
	
	if (success != false) {
		*cmd_arg_num = (org_arg_cnt + add_arg_cnt);
		cmd_arg = (char **)calloc((org_arg_cnt + add_arg_cnt), sizeof(char *));
		
		if (cmd_arg == NULL) {
			success = false;
		}
	}
	
	if (success != false) {
		int idx_org_arg = 0;
		int idx_cmd_arg = 0;

		for(idx_org_arg = 0 ; idx_org_arg < org_arg_cnt ; idx_org_arg++){
			if (org_arg[idx_org_arg] != NULL){
				if (strcasecmp( org_arg[idx_org_arg], REAR_ARGUMENT) == 0 ){
					int idx_add_arg = 0;
					char *next = NULL;
					char *tmpstr = ppdvalue;
					
					for (idx_add_arg = 0 ; idx_add_arg < add_arg_cnt ; idx_add_arg++ ){
						cmd_arg[idx_cmd_arg] = get_gs_option(tmpstr, &next);
						tmpstr = next;

						if (cmd_arg[idx_cmd_arg] == NULL) {
							success = false;
							break;
						}
						
						idx_cmd_arg = idx_cmd_arg + 1;
					}
				}
				
				if (success != false) {
					cmd_arg[idx_cmd_arg] = strdup(org_arg[idx_org_arg]);
					if (cmd_arg[idx_cmd_arg] == NULL) {
						success = false;
						break;
					}
				} else {
					break;
				}
				
			} else {
				cmd_arg[idx_cmd_arg] = NULL;
			}
			
			idx_cmd_arg = idx_cmd_arg + 1;
		}
	}
	
	if (ppdvalue != NULL) {
		free(ppdvalue);
		ppdvalue = NULL;
	}
	
	if (success == false) {
		if (cmd_arg != NULL) {
			free_gs_cmd_arg(cmd_arg, (org_arg_cnt + add_arg_cnt));
			cmd_arg = NULL;
		}
	}

	return cmd_arg;
}
