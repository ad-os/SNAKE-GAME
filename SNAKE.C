#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
char c[50][50], r;
int n, x=1, s=1, h, g, e=0, q=0, l=1, k=1, SCORE = 0;
void blank();
void add_length();
int generate_food_x()
{
    return random(n);
}
int generate_food_y()
{
    return random(n);
}
int checks()
{
	int flag = 0;
	if(x == 0 || x == n-1 || s == 0 || s == n-1)
	{
		flag=1;
	}
	return flag;
}
void pressed_key()
{
      if(r == 'w')
      {
		s--;
      }
      else if(r == 's')
      {
		s++;
      }
      else if(r == 'a')
      {
		x--;
      }
      else if(r == 'd')
      {
		x++;
      }
      else
      {
		x++;
      }
}
void prints()
{
    int i, j;
    for(i = 0; i < n; i++)
    {
	c[0][i] = '*';
	c[i][0] = '*';
	c[n-1][i] = '*';
	c[i][n-1] = '*';
    }
    for(i = 0; i < n; i++)
    {
	for(j = 0; j < n; j++)
	{
	    printf("%c ", c[i][j]);
	}
	printf("\n");
    }
    printf("\nSCORE : %d", SCORE);
    printf("\n");
}

void food()
{
	randomize();
	g = generate_food_x();
	h = generate_food_y();
	while(g == 0 || h == 0 || g == n-1 || h == n-1)
	{
		g = generate_food_x();
		h = generate_food_y();
	}
}
void eat()
{
	if(s == g && x == h)
	{
		food();
		SCORE++;
		k++;
		add_length();
	}
}
void hits()
{
	r = getch();
	blank();
	pressed_key();
	eat();
	add_length();
}

void blank()
{
	int i;
	for(i = 0; i < k; i++)
	{
		c[s][x-i] = ' ';
		c[s][x+i] = ' ';
		c[s-i][x] = ' ';
		c[s+i][x] = ' ';
	}
}

void add_length()
{
	int i;
	e = 0;
	q = 0;
	for(i = 1; i <= k; i++)
	{
		if(r == 'a')
		{
			c[s][x+q] = '>';
		}
		else if(r == 's')
		{
			c[s-e][x] = '>';
		}
		else if(r == 'w')
		{
			c[s+e][x] = '>';
		}
		else if(r == 'd')
		{
			c[s][x-q] = '>';
		}
		else
		{
			c[s][x+q] = '>';
		}
		e++;
		q++;
	}
}

int main()
{
    int i, j;
    long long flag;
    clrscr();
    printf("Enter the size of the matrix : ");
    scanf("%d", &n);
    for(i = 1; i < n-1; i++)
    {
	for(j = 1; j < n-1; j++)
	{
	    c[i][j] = ' ';
	}
    }
    food();
    c[s][x] = '>';
    while(1)
    {
	clrscr();
	c[g][h] = '$';
	prints();
	if(kbhit())
	{
		hits();
		if(checks())
		{
			printf("\nGAME OVER.\n");
			getch();
			return 0;
		}
		delay(500);
		continue;
	}
	blank();
	c[g][h] = ' ';
	pressed_key();
	eat();
	if(checks())
	{
		printf("\nGAME OVER.\n");
		getch();
		return 0;
	}
	add_length();
	delay(500);
    }
}

