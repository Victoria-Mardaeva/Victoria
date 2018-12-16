/*
� ���������� �������, ��������� �� n ������������ ���������, ���������:
1) ������� �������������� ���� ������������� ���������;
2) ����� ���������, ������������� �� ������������� ��������.
*/

#include <stdio.h> 
#include <locale.h> 
#include <time.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	char c = '\n';
	int num = 0; //����� ������� ����
	int size = 0;
	int *a = NULL;
	bool flag = false;

	int t = 0;
	float pol = 0; //��� ������������� �������� �������
	float kolvo = 0; //���-�� ���� ������������� ��������� �������
	int max = 0;
	int doo = 0; //����� ��������� ������� �� �������������
	do
	{
		do
		{
			printf("\n*************************************************************************\n");
			printf("**                              ����	                               **\n");
			printf("*************************************************************************\n");
			printf("**                  ������� ����� ������� �� 1 �� 5:                   **\n");
			printf("** 1. ���� ��������� ������� � ����������                              **\n");
			printf("** 2. ���������� ������� ���������� �������                            **\n");
			printf("** 3. ������� �������������� ���� ������������� ��������� �������      **\n");
			printf("** 4. ����� ��������� �������, ������������� �� ������������� �������� **\n");
			printf("** 5. �����                                                            **\n");
			printf("*************************************************************************\n");
			while (scanf_s("%d%c", &num, &c, 1) != 2 || c != '\n')
			{
				while (getchar() != '\n');
			}
		} while ((num <= 0) || (num > 5));



		switch (num)
		{
		case 1:
			size = 0;
			do
			{
				printf("������� ������ �������: ");
				while ((scanf_s("%d%c", &size, &c, 1) != 2 || c != '\n'))
				{
					while (getchar() != '\n');
				}
			} while (size <= 0);
			a = new int[size];
			for (int i = 0; i < size; i++)
			{
				do
				{
					printf("������� %d-� ������� ������������������: ", i + 1);
					while ((scanf_s("%d%c", &a[i], &c, 1) != 2 || c != '\n'))
					{
						while (getchar() != '\n');
					}
				} while ((a[i] <= SHRT_MIN) || (a[i] >= SHRT_MAX));
			}
			printf("�� ��������� ������ ������ �������:\n");
			for (int i = 0; i < size; i++)
			{
				printf("%d ", a[i]);
			}
			flag = true;
			break;

		case 2:
			if (size > 0)
			{
				delete[] a;
			}
			size = 0;
			do
			{
				printf("������� ������ �������: ");
				while (scanf_s("%d%c", &size, &c, 1) != 2 || c != '\n')
				{
					while (getchar() != '\n');
				}
			} while (size <= 0);
			printf("������ �������� ���������� �������:\n");
			a = new int[size]();
			for (int i = 0; i < size; i++)
			{
				a[i] = rand() - rand();
				printf("%d ", a[i]);
			}
			flag = true;
			break;

		case 3:
			if (flag == true)
			{
				for (int i = 0; i < size; i++)
				{
					if (a[i] > 0)
					{
						pol = a[i] + pol;
						kolvo = kolvo + 1;
					}
				}
				printf("\n������� �������������� ���� ������������� ��������� = %.2f", pol / kolvo);
			}
			break;

		case 4:
			if (flag == true)
			{
				max = a[0];
				for (int i = 0; i < size; i++)
				{
					if (a[i] > max)
					{
						max = a[i];
						t = i;
					}
				}
				printf("\n������������ ����e�� �����: %d", max);
				for (int i = 0; i < t; i++)
				{
					doo = doo + a[i];
				}
				printf("\n����� ���������, ������������� �� ������������� ��������: %d", doo);
			}
			break;


		case 5:
			break;
		}

	} while (num != 5);
	delete[] a;
	getchar();
	getchar();
}