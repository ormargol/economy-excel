#include <stdio.h>

#define DATA_DIR "C:\\Users\\DELL-PC\\Desktop\\Dropbox\\כלכלה 2017\\updated_data"

int main(int argc, char** argv) {
	int year = 2016;
	int month, type, line, line_addon;
	char type_names[5][20] = {
		"bank_account",
		"orr_credit",
		"reut_credit",
		"orr_direct",
		"reut_direct"};
	for (month = 1; month <= 12; month++) {
		for (type = 0; type < 5; type++) {
			if (type == 0) {
				line_addon = 0;
			} else {
				line_addon = 3;
			}
			for (line = 4 + line_addon; line < 204 + line_addon; line++) {
				printf("=iferror(if('" DATA_DIR "\\%s\\", type_names[type]);
				printf("[%d_%s%d_%s.xls]", year, month < 10? "0":"", month, type_names[type]);
				if (type == 0) {
					printf("%d_%s%d_%s'!", year, month < 10? "0":"", month, type_names[type]);
				} else {
					printf("Transactions'!");
				}
				printf("%c%d=0,\"\",", type == 0? 'E':'B', line);
				printf("'" DATA_DIR "\\%s\\", type_names[type]);
				printf("[%d_%s%d_%s.xls]", year, month < 10? "0":"", month, type_names[type]);
				if (type == 0) {
					printf("%d_%s%d_%s'!", year, month < 10? "0":"", month, type_names[type]);
				} else {
					printf("Transactions'!");
				}
				printf("%c%d),\"\")\n", type == 0? 'E':'B', line);
			}
		}
	}
	return 0;
}
