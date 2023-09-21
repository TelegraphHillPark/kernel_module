#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main() {
	char filename[100];
	unsigned int interval;

	printf("Enter the filename: ");
	scanf("%s", filename);
	if (strchr(filename, '/') != NULL) {
		perror("The input string contains a '/'.\n");
		return 1;
	}
	if (strcmp(filename, "0") == 0) {
		perror("The input string is equal to '0'.\n");
		return 1;
	}

	printf("Enter the interval in seconds: ");
	if (scanf("%u", &interval) == 1) {
		printf("You entered a valid integer: %u\n", interval);
	}
	else {
		perror("Invalid input.\n");
		return 1;
	}

	FILE *config_file = fopen("parameters.conf", "w");
	if (!config_file) {
		perror("Error opening configuration file\n");
		return 1;
	}

	fprintf(config_file, "filename=\"%s\"\n", filename);
	fprintf(config_file, "interval=%u\n", interval);
	fclose(config_file);

	printf("Configuration file updated successfully!\n");

	return 0;
}
