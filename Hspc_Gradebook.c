#include<stdio.h>
struct students{
	char names[100];
    int scores[100];
    float avg;
    char grade;
};
typedef struct students Students;

struct gradebook{
	char course[100];
	float weights[100];
	int n_students;	
	int n_scores;
	struct students st[100];
};
typedef struct gradebook gradebook;

Students input_one_student(int n_scores)
{
    Students s;
    scanf("%s", s.names);
    for(int i=0 ; i<n_scores ; i++)
    {
        scanf("%d", &s.scores[i]);
    }
    return s;
}

gradebook input_one_gradebook()
{
	gradebook gb;
	scanf("%s", &gb.course);
	scanf("%d%d", &gb.n_students, &gb.n_scores);
	for(int i=0; i<gb.n_scores; i++)
	{
		scanf("%f", &gb.weights[i]);
	}
	for(int i=0; i<gb.n_scores; i++)
	{
		gb.st[i] = input_one_student(gb.n_scores);
	}
	return gb;
}

void input_n_gradebook(int n, gradebook gb[n])
{
	for(int i=0 ; i<n ; i++)
	{
		gb[i] = input_one_gradebook();
	}
}

char grade_compute(Students s)
{
	if(s.avg>=0 && s.avg<60)
		s.grade = 'F';
	else if(s.avg>=60 && s.avg<70)
		s.grade = 'D';
	else if(s.avg>=70 && s.avg<80)
		s.grade = 'C';
	else if(s.avg>=80 && s.avg<90)
		s.grade = 'B';
	else
		s.grade = 'A';
	return s.grade;
}

compute_grade_one_student(gradebook *pgb)
{
	float total_weights = 0.0;
	float sum;
	for(int i=0 ; i< pgb->n_scores ; i++)
	{
		total_weights = total_weights + pgb->weights[i];
	}
	for(int i=0 ; i< pgb->n_students ; i++)
	{
		sum = 0.0;
		for(int j=0 ; j< pgb->n_scores ; j++)
		{
			sum = sum + ((pgb->weights[j])*(pgb->st[i].scores[j]));
		}
		pgb->st[i].avg = sum / total_weights;
		pgb->st[i].grade = grade_compute(pgb->st[i]);
	}
}

void compute_grade_n_students(int n, gradebook course[n])
{
	for(int i=0 ; i<n ; i++)
	{
		compute_grade_one_student(&course[i]);
	}
}

void print_grade_one_student(Students s)
{
	printf("%s \t %f \t %c\t \n", s.names, s.avg, s.grade);
}

void print_grade_n_students(int n, gradebook courses[n])
{
	for(int i=0 ; i<n ; i++)
	{
		printf("%s \n", courses[i].course);
		for(int j=0 ; j<courses[i].n_students ; j++)
		{
			print_grade_one_student(courses[i].st[j]);
		}
	}
}

int main()
{
	gradebook gb[100];
	int n;
	scanf("%d", &n);
	input_n_gradebook(n, gb);
	compute_grade_n_students(n, gb);
	print_grade_n_students(n, gb);
	return 0;
}
