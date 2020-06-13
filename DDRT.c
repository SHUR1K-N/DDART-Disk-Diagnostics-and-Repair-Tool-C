#include <stdio.h>
#include <string.h>
#include <time.h>

	//Eye of Agamotto stuff here
	void delay(int number_of_seconds)
{ 
    int milli_seconds = 1 * number_of_seconds; 
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds); 
}

int main()
{
	int i, num, gsec=0, bsec=0, verify=0, exit=0;
	char mem[100], YN, mem1[100];
	system("color F0");
	
				reinput1:
					
	//Sector state input
	printf("\nNumber of sectors: ");
	fflush(stdin), scanf("%d", &num);
	if(num>0 && num<100 && num!="%d")
	{	
		printf("\nEnter sector states (Good/Bad): \n");
		for (i=0; i<num; i++)
		{
			scanf("%s", &mem[i]);
		}
		system("cls");
		printf("\nRunning memory diagnostic...\n"), delay(1500);
		for (i=0; i<num; i++)
		{		
			//Scanning sectors
			if (mem[i]=='G' || mem[i]=='g')
			printf("\033[0;32m"),
			printf("\nSector %d good\n", i+1),
			printf("\033[0m"), delay(900);
			else if (mem[i]=='B' || mem[i]=='b')
			printf("\033[0;31m"),
			printf("\n\tBad sector found at %d!\n", i+1),
			printf("\033[0m"), delay(900);
			else
			printf("\033[0;33m"),
			printf("\n\tInvalid data at %d: '%c'\n", i+1, mem[i]),
			printf("\033[0m"), delay(900);
		}
	}
	else if(num==0)
	goto quit;
	else
	{
		printf("\nInvalid input, please try again.\n");
		goto reinput1;
	}
	
	//Displaying scan result(s)
	delay(1000), printf("\n\nData assessed:\n");
	printf("Start of Data -> "), delay(100);
	for (i=0; i<num; i++)
	{
		if (mem[i]=='g' || mem[i]=='G')
		printf("\033[0;32m"),
		printf("%c", mem[i]),
		printf("\033[0m"), delay(200);
		else if(mem[i]=='b' || mem[i]=='B')
		printf("\033[0;31m"),
		printf("%c", mem[i]),
		printf("\033[0m"), delay(200);
		else
		continue;
		if (i<num-1)
		{
			printf(", ");
		}
	}
	printf(" <- End of Data"),	delay(900);
	for (i=0; i<num; i++)
	{
		if (mem[i]=='G' || mem[i]=='g')
		gsec++;
		else if (mem[i]=='B' || mem[i]=='b')
		bsec++;
	}
	delay(700);
	printf("\n\nNumber of good sectors: %d", gsec);
	printf("\nNumber of bad sectors: %d", bsec);
	delay(1000);
	bsec=0, gsec=0;
	for (i=0; i<num; i++)
	{
		if (mem[i]=='g' || mem[i]=='G')
		verify++;
		}
		strcpy(mem1, mem);
		if (verify==num)
		{
			goto cleaned;
		}
		else
		
					reinput2:
						
		//Bypassing sectors
		printf("\n\nBypass bad sectors?: ");
		scanf("%s", &YN);
		if (YN=='Y' || YN=='y' || YN=="yes" || YN=="YES" || YN=="Yes")
		{
			printf("\nAttempting to create bypasses over bad sectors... \n\n"), delay(2000);
			printf("New data stream:\n"), delay(500);
			printf("Start of Data -> "), delay(100);
			for (i=0; i<num; i++)
			{
				if (mem1[i]=='G' || mem1[i]=='g')
				{
					printf("\033[0;32m"),
					printf("%c", mem1[i]),
					printf("\033[0m"), delay(200);
				}
			}
			printf(" <- End of Data"),	delay(900);
		}
		else if (YN=='N' || YN=='n' || YN=="no" || YN=="NO" || YN=="No")
		{				
		
					reinput3:
						
			//Repairing sectors
			printf("\nRepair bad sectors?: ");
			scanf("%s", &YN);
			if (YN=='Y' || YN=='y' || YN=="yes" || YN=="YES" || YN=="Yes")
			{
				printf("\nAttempting to repair bad sectors... \n\n"), delay(2000);
				printf("New data stream:\n"), delay (500);
				printf("Start of Data -> "), delay(100);
				for (i=0; i<num; i++)
				{
				if (mem1[i]=='G' || mem1[i]=='g')
				printf("\033[0;32m"),
				printf("%c", mem1[i]),
				printf("\033[0m"), delay(200);
				else if (mem1[i]=='B' || mem1[i]=='b')
				mem1[i]='G',
				printf("\033[0;33m"),
				printf("%c", mem1[i]),
				printf("\033[0m"), delay(200);
				}
				printf(" <- End of Data"),	delay(900);
			}
			else if (YN=='N' || YN=='n' || YN=="no" || YN=="NO" || YN=="No")
			printf("\n\nThank you for using this diagnostic tool."), exit++;
			else
			{
				printf("\nInvalid input, please input only either Y or N.");
				goto reinput3;
			}
		}
		else
		{
			printf("\nInvalid input, please input only either Y or N.");
			goto reinput2;
		}
		if (exit==1)
		{
			goto quit;
		}
		for (i=0; i<num; i++)
		{
			if (mem1[i]=='G' || mem1[i]=='g')
			gsec++;
			else if (mem1[i]=='B' || mem1[i]=='b')
			bsec++;
		}
		delay(700);
		printf("\n\nNumber of good sectors: %d", gsec);
		printf("\nNumber of bad sectors: %d", bsec);
		if (bsec>0)
		{
			goto bypassed;
		}
		else
		goto repaired;
		
		delay(1000);

	
						quit:
		printf("\nThank you for using this diagnostic tool.\n");
		printf("\nPress any key to exit.");
		getch();
		return 0;
	
						cleaned:
		printf("\033[0;32m"),
		printf("\n\nAll scanned sectors are good!"),
		printf("\033[0m");
		goto quit;
		
						bypassed:
		printf("\n\nSectors successfully bypassed!");
		goto quit;
			
						repaired:
		printf("\n\nSectors successfully repaired!");
		goto quit;
}
