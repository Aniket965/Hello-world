#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct stats_cpu {
	unsigned long long cpu_user;
	unsigned long long cpu_nice;
	unsigned long long cpu_sys;
	unsigned long long cpu_idle;
	unsigned long long cpu_iowait;
	unsigned long long cpu_steal;
	unsigned long long cpu_hardirq;
	unsigned long long cpu_softirq;
	unsigned long long cpu_guest;
	unsigned long long cpu_guest_nice;
}; 

#define STAT "/proc/stat"
/*
 ***************************************************************************
 * Read CPU statistics.
 * Remember that this function is used by several sysstat commands!
 *
 * IN:
 * @st_cpu	Buffer where structures containing stats will be saved.
 * @nr_alloc	Total number of structures allocated. Value is >= 1.
 *
 * OUT:
 * @st_cpu	Buffer with statistics.
 *
 * RETURNS:
 * Highest CPU number(*) for which statistics have been read.
 * 1 means CPU "all", 2 means CPU 0, 3 means CPU 1, etc.
 * Or -1 if the buffer was too small and needs to be reallocated.
 *
 * (*)This doesn't account for all processors in the machine in the case
 * where some CPU are offline and located at the end of the list.
 ***************************************************************************
 */
int read_stat_cpu(struct stats_cpu *st_cpu)
{
	FILE *fp;
	struct stats_cpu *st_cpu_i;
	struct stats_cpu sc;
	char line[8192];
	int proc_nr;
	int cpu_read = 0;

	if ((fp = fopen(STAT, "r")) == NULL) {
		exit(2);
	}

	while (fgets(line, sizeof(line), fp) != NULL) {

		if (!strncmp(line, "cpu ", 4)) {

			/*
			 * All the fields don't necessarily exist,
			 * depending on the kernel version used.
			 */
			memset(st_cpu, 0, sizeof(struct stats_cpu));

			/*
			 * Read the number of jiffies spent in the different modes
			 * (user, nice, etc.) among all proc. CPU usage is not reduced
			 * to one processor to avoid rounding problems.
			 */
			sscanf(line + 5, "%llu %llu %llu %llu %llu %llu %llu %llu %llu %llu",
			       &st_cpu->cpu_user,
			       &st_cpu->cpu_nice,
			       &st_cpu->cpu_sys,
			       &st_cpu->cpu_idle,
			       &st_cpu->cpu_iowait,
			       &st_cpu->cpu_hardirq,
			       &st_cpu->cpu_softirq,
			       &st_cpu->cpu_steal,
			       &st_cpu->cpu_guest,
			       &st_cpu->cpu_guest_nice);

			if (!cpu_read) {
				cpu_read = 1;
			}

		}

		else if (!strncmp(line, "cpu", 3)) {
			/* All the fields don't necessarily exist */
			memset(&sc, 0, sizeof(struct stats_cpu));
			/*
			 * Read the number of jiffies spent in the different modes
			 * (user, nice, etc) for current proc.
			 * This is done only on SMP machines.
			 */
			sscanf(line + 3, "%d %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu",
			       &proc_nr,
			       &sc.cpu_user,
			       &sc.cpu_nice,
			       &sc.cpu_sys,
			       &sc.cpu_idle,
			       &sc.cpu_iowait,
			       &sc.cpu_hardirq,
			       &sc.cpu_softirq,
			       &sc.cpu_steal,
			       &sc.cpu_guest,
			       &sc.cpu_guest_nice);

			st_cpu_i = st_cpu + proc_nr + 1;
			*st_cpu_i = sc;

			if (proc_nr + 2 > cpu_read) {
				cpu_read = proc_nr + 2;
			}
		}
	}

	fclose(fp);
	return cpu_read;
}


void print_cpuutil(struct stats_cpu* cur){
	printf("Hi %lu\n",cur->cpu_user);
}

int main(){
	struct stats_cpu cur;
	int ii=0;
	while(ii<2){
		printf("read cpu = %d %d\n",read_stat_cpu(&cur),ii);
		print_cpuutil(&cur);
		sleep(1);
		ii++;
	}
}
