#include<stdio.h>
#include<stdlib.h>
#include"���Ա�ͷ�ļ�.h"
#include "windows.h"

void main() {
	SqList L;
	ElemType e, cur_e, pre_e, next_e,X,S,T;
	float M=0;
	int D;
	int i, n, select, t;
	InitList_Sq(&L);
	CreateList_Sq(&L);
	ListTraverse_Sq(L);
	do {
		printf("*************************************************\n");
		printf("1:�ж����Ա��Ƿ�Ϊ��\n");
		printf("2:��ѯ���Ա�ĳ���\n");
		printf("3:�������Ա�ĵ�i��Ԫ��\n");
		printf("4:����ֵΪx��Ԫ�����ڵ�λ��\n");
		printf("5:����Ԫ��x��ǰ��Ϊ\n");
		printf("6:����Ԫ��x�ĺ��Ϊ\n");
		printf("7:�����Ա��i��λ��ǰ������Ԫ��x\n");
		printf("8:ɾ�����Ա��i��Ԫ�أ�������ֵ\n");
		printf("9:�������Ա�\n");
		printf("10:������Ա�\n");
		printf("11:�޸ĵ�i��Ԫ��\n");
		printf("12:ɾ��������Сֵ��βԪ�����ԭλ��\n");
		printf("13:�������Ա�\n");
		printf("14:ɾ��ָ��XԪ��\n");
		printf("15:ɾ������ֵS��T֮�������Ԫ��S<T\n");
		printf("16:ɾ������SС��T������Ԫ��S<T\n");
		printf("17:ɾ���ظ�Ԫ��(�����ⷨ)\n");
		printf("18:����ȥ��\n");
		printf("19:�ϲ��������\n");
		printf("20:˳���λ�û���\n");
		printf("21:����X,�ҵ�X�򽻻������Ԫ��,û�ҵ��������˳���\n");
		printf("22:˳�������p����λ\n");
		printf("23:��������˳���Ѱ����λ��\n");
		printf("24:����������Ԫ��\n");
		printf("40:�鲢����\n");
		printf("50:�������Ա�����\n");
		printf("0:����\n");
		printf("**************************************\n");
		printf("������ѡ��");
		scanf_s("%d", &select);
		switch (select) {
		case 1: if (ListEmpty_Sq(L))
			printf("���Ա�Ϊ��\n");
			  else
			printf("���Ա�ǿ�\n"); break;

		case 2:ListLength_Sq(L);
			printf("���Ա�ĳ���Ϊ%d\n", (L.length)); break;

		case 3: printf("\ni=");
			scanf_s("%d", &i);
			if (GetElem_Sq(L, i, &e) == ERROR)
				printf("iֵ���Ϸ�\n");
			else
				printf("��%d��Ԫ�ص�ֵΪ%d\n", i, e); break;

		case 4:printf("\nx=");
			scanf_s("%d", &e);
			i = LocateElem_Sq(L, e);
			if (i <= L.length)
				printf("��%d��Ԫ�ص�ֵΪ%d\n", i, e);
			else
				printf("���Ա���û��ֵΪ%d��Ԫ��\n", e); break;

		case 5:printf("\nx=");
			scanf_s("%d", &t);
			if (PriorElem_Sq(L, t, &e) == 1)
				printf("Ԫ��%d��ǰ��Ϊ%d\n\n", t, e);
			else
				printf("Ԫ��%d��ǰ��\n", t); break;

		case 6:printf("\nx=");
			scanf_s("%d", &t);
			if (NextElem_Sq(L, i, t, &e) == 1)
				printf("Ԫ��%d�ĺ��Ϊ%d\n\n", t, e);
			else
				printf("Ԫ��%d�޺��\n", t); break;

		case 7:printf("\ni=");
			scanf_s("%d", &i);
			printf("\nx=");
			scanf_s("%d", &e);
			if (ListInsert_Sq(L, i, e) == ERROR)
				printf("iֵ���Ϸ�\n\n");
			else {
				printf("�µ����Ա�Ϊ: ");
				ListTraverse_Sq(L);
			}break;

		case 8:printf("\ni=");
			scanf_s("%d", &i);
			if (ListDelete_Sq(&L, i, &e) == ERROR)
				printf("iֵ���Ϸ�\n\n");
			else {
				printf("��ɾ���ĵ�%d��Ԫ�ص�ֵΪ%d\n", i, e);
				printf("�µ����Ա�Ϊ:");
				ListTraverse_Sq(L);
			} break;

		case 9:ListTraverse_Sq(L); break;

		case 10:ClearList_Sq(&L);
			printf("������Ա�ɹ�,���Ա�����%d \n\n", L.length); break;
		
		case 11:printf("\ni=");
			scanf_s("%d", &i);
			printf("\nx=");
			scanf_s("%d", &cur_e);
			t=AlterElem_Sq(L, i,e,cur_e );
			if (t == ERROR) {
				printf("iֵ���Ϸ�");
			}
			else {
				printf("�µ����Ա�Ϊ��\n");
				ListTraverse_Sq(L);
			}break;

		case 12:printf("ɾ��������Сֵ����βԪ�ش��档\n");
			DeleteMinElem_Sq(L, e);
			printf("ɾ����Ԫ��Ϊ��%d\n", e);
			ListTraverse_Sq(L);
			break;

		case 13:printf("�������Ա�");
			Convert_Sq(L);
			ListTraverse_Sq(L);
			break;

		case 14:printf("ɾ��ָ��X\nX=");
			scanf_s("%d", &X);
			DeleteX(L, X);
			ListTraverse_Sq(L);
			printf("�±���%d",L.length);
			break;

		case 15:printf("ɾ������ֵS��T֮�������Ԫ��S<T\n");
			printf("S=");
			scanf_s("%d", &S);
			printf("T=");
			scanf_s("%d", &T);
			DeleteStoT(L, S, T);
			ListTraverse_Sq(L);
			break;
		case 16: printf("ɾ������SС��T������Ԫ��S<T\n");
			printf("S=");
			scanf_s("%d", &S);
			printf("T=");
			scanf_s("%d", &T);
			DeleteS_T(L, S, T);
			ListTraverse_Sq(L);
			break;

		case 17: printf("����ȥ��\n");
			DuplicatesElimination_Violence(L);
			ListTraverse_Sq(L);
			break;

		case 18: printf("����ȥ��\n");
			DuplicatesElimination_sort(L);
			ListTraverse_Sq(L);
			break;

		case 19:printf("�����ϲ��ϲ�����\n");
			SqList MergeList1;
			SqList MergeList2;
			InitList_Sq(&MergeList1);
			InitList_Sq(&MergeList2);
			D=CreateList_Sq(&MergeList1);
			if (D == OK) {
				merge_sort(MergeList1, MergeList1, 0, MergeList1.length - 1);
				ListTraverse_Sq(MergeList1);
			}
			else {
				printf("����ʧ��");
				break;
			}
			D = CreateList_Sq(&MergeList2);
			if (D == OK) {
				merge_sort(MergeList2, MergeList2, 0, MergeList2.length - 1);
				ListTraverse_Sq(MergeList2);
			}
			else {
				printf("����ʧ��");
				break;
			}
			 SqList Mergelist=MergeList(MergeList1, MergeList2);
			 ListTraverse_Sq(Mergelist);
			 break;

		case 20:printf("˳���λ�û���\n");
			printf("a����Ԫ�ظ���");
			scanf_s("%d", &S);
			printf("b����Ԫ�ظ���");
			scanf_s("%d", &T);
			Reverse(L, 0, S + T-1, L.length);
			Reverse(L, 0, T - 1, L.length);
			Reverse(L, T, S + T - 1, L.length);
			ListTraverse_Sq(L);
			break;

		case 21:printf("����X,�ҵ�X�򽻻������Ԫ��,û�ҵ��������˳���\n");
			merge_sort(L, L, 0, L.length-1);
			ListTraverse_Sq(L);
			printf("X=");
			scanf_s("%d", &X);
			SearchX(L, X);
			ListTraverse_Sq(L);
			break;

		case 22:printf("˳�������p����λ\n");
			int p;
			printf("P=");
			scanf_s("%d", &p);
			LeftTranslation_p(L, p);
			ListTraverse_Sq(L);
			break;

		case 23:printf("���������������(0<n,m<1000)������˳���\n");
			SqList ROL1;
			SqList ROL2;
			InitList_Sq(&ROL1);
			InitList_Sq(&ROL2);
			CreatOrderList_sq(ROL1);
			//CreateList_Sq(&ROL1);
			ListTraverse_Sq(ROL1);
			printf("���Ա�ĳ���Ϊ%d\n", ROL1.length);
			Sleep(1000);
			//CreateList_Sq(&ROL2);
			CreatOrderList_sq(ROL2);
			ListTraverse_Sq(ROL2);
			printf("���Ա�ĳ���Ϊ%d\n", ROL2.length);
			printf("�����𰸣�\n");
			M=M_Search(ROL1, ROL2);
			printf("��λ��Ϊ��%f\n", M);
			break;

		case 24:printf("������Ԫ��\n");
			X = MainElem_wangdao(L);
			printf("��Ԫ��Ϊ��%d", X);
			break;

		case 25:printf("Ѱ��δ���ֵ���С����\n");
			X = MinIntegerNS(L);
			printf("��Сδ���ֵ�����Ϊ��%d\n", X);
			break;

		case 40:
			clock_t start, end;
			start = clock();
			merge_sort(L, L, 0, L.length-1);
			end = clock();
			ListTraverse_Sq(L);
			printf("�鲢����ʱ��Ϊ�� %f ms\n", (double)(end - start)*1000 / CLOCKS_PER_SEC);
			break;

		case 50:printf("��ʼ�����������Ա�����\n");
			InitList_Sq(&L);
			D=CreateList_Sq(&L);
			if(D==OK){
			ListTraverse_Sq(L);
			}
			else {
				break;
			}
			break;

		case 0: printf("��������\n"); break;
		default:printf("����ѡ�����! \n");
		}
	} while (select != 0);
	DestoryList_Sq(& L);
}
