#include<host_bsp.h>

int main(int argc, char **argv)
{
	bsp_init("messages_kernel.elf", argc, argv);
	bsp_begin(16);

	int tagsize = sizeof(int);
	ebsp_set_tagsize(&tagsize);

	ebsp_spmd();

	bsp_end();

	return 0;
}
