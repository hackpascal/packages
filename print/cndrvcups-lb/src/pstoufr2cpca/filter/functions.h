#ifndef _functions_
#define _functions_

#define	LINE_BUF_SIZE	1024
#define	BUFSIZE	256

char **init_cmd_arg(char *org_arg[], int org_arg_cnt, int *cmd_arg_num);
int GetValue(char *p_line_buf, char *p_value_buf, int value_len);

#endif	// _functions_

