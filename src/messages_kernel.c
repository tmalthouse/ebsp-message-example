#include<stdlib.h>
#include<stdio.h>
#include<e_bsp.h>


int random_core(int numcores)
{
	return rand()%numcores;
}

int main(int argc, char **argv)
{
	bsp_begin();
	int s = bsp_pid();
	int p = bsp_nprocs();	

	int tag = s;


	for (int i=0; i<10; i++) {
		int destination = random_core(p);
		char message[64];
		sprintf(message, "Hello to core %d from core %d\n", destination, s);
		bsp_send(destination, &(tag), message, 64);
		tag += p;
	}

	bsp_sync();		
	
	int packets = 0;
	int accum_bytes = 0;
	
	bsp_qsize(&packets, &accum_bytes);

	char payload_in[64];
	int payload_size = 0;
	int tag_in = 0;
	for (int i=0; i<packets; i++) {
		bsp_get_tag(&payload_size, &tag_in);
		bsp_move(&payload_in, payload_size);
		ebsp_message("%s", payload_in);
	}
	bsp_end();
}
