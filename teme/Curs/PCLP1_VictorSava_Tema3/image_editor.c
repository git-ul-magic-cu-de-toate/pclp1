// SAVA Victor 311CA

#include "utils.h"

int main(void)
{
	char line[LEN_MAX], command[LEN_MAX], param[LEN_MAX];
	image_t image;
	select_t select_section;
	init(&image);

	while (fgets(line, sizeof(line), stdin)) {
		if (sscanf(line, "%s", command) == 1) { // this looks dumb but whatever
			;                                   // coding style checker ...
		}

		strcpy(param, line + strlen(command) + 1);

		if (!strcmp(command, "LOAD")) {
			// LOAD Section
			free_image(&image);
			load_command(&image, &select_section, param);
		} else if (!strcmp(command, "SELECT")) {
			// SELECT Section
			select_command(&image, &select_section, param);
		} else if (!strcmp(command, "ROTATE")) {
			// ROTATE Section
			rotate_command(&image, &select_section, param);
		} else if (!strcmp(command, "CROP")) {
			// CROP Section
			crop_command(&image, &select_section);
		} else if (!strcmp(command, "HISTOGRAM")) {
			// HISTOGRAM Section
			histogram_command(&image, param);
		} else if (!strcmp(command, "EQUALIZE")) {
			// EQUALIZE Section
			equalize_command(&image);
		} else if (!strcmp(command, "APPLY")) {
			// APLLY Section
			apply_command(&image, &select_section, param);
		} else if (!strcmp(command, "SAVE")) {
			// SAVE Section
			save_command(&image, param);
		} else if (!strcmp(command, "EXIT")) {
			// EXIT Section
			exit_command(&image);
			return 0;
		}

		invalid_command(command);
	}
}
