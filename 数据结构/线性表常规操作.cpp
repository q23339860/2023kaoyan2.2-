#include<stdio.h>
#include<stdlib.h>
#include"线性表头文件.h"
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
		printf("1:判断线性表是否为空\n");
		printf("2:查询线性表的长度\n");
		printf("3:查找线性表的第i个元素\n");
		printf("4:查找值为x的元素所在的位置\n");
		printf("5:数据元素x的前驱为\n");
		printf("6:数据元素x的后继为\n");
		printf("7:在线性表第i个位置前插入新元素x\n");
		printf("8:删除线性表第i个元素，返回其值\n");
		printf("9:遍历线性表\n");
		printf("10:清空线性表\n");
		printf("11:修改第i个元素\n");
		printf("12:删除表中最小值由尾元素替代原位置\n");
		printf("13:倒置线性表\n");
		printf("14:删除指定X元素\n");
		printf("15:删除给定值S与T之间的所有元素S<T\n");
		printf("16:删除大于S小于T的所有元素S<T\n");
		printf("17:删除重复元素(暴力解法)\n");
		printf("18:排序去重\n");
		printf("19:合并两有序表\n");
		printf("20:顺序表位置互换\n");
		printf("21:查找X,找到X则交换其后置元素,没找到则按序插入顺序表。\n");
		printf("22:顺序表左移p个单位\n");
		printf("23:两个有序顺序表寻找中位数\n");
		printf("24:王道数组主元素\n");
		printf("40:归并排序\n");
		printf("50:填入线性表数据\n");
		printf("0:结束\n");
		printf("**************************************\n");
		printf("请输入选择：");
		scanf_s("%d", &select);
		switch (select) {
		case 1: if (ListEmpty_Sq(L))
			printf("线性表为空\n");
			  else
			printf("线性表非空\n"); break;

		case 2:ListLength_Sq(L);
			printf("线性表的长度为%d\n", (L.length)); break;

		case 3: printf("\ni=");
			scanf_s("%d", &i);
			if (GetElem_Sq(L, i, &e) == ERROR)
				printf("i值不合法\n");
			else
				printf("第%d个元素的值为%d\n", i, e); break;

		case 4:printf("\nx=");
			scanf_s("%d", &e);
			i = LocateElem_Sq(L, e);
			if (i <= L.length)
				printf("第%d个元素的值为%d\n", i, e);
			else
				printf("线性表中没有值为%d的元素\n", e); break;

		case 5:printf("\nx=");
			scanf_s("%d", &t);
			if (PriorElem_Sq(L, t, &e) == 1)
				printf("元素%d的前驱为%d\n\n", t, e);
			else
				printf("元素%d无前驱\n", t); break;

		case 6:printf("\nx=");
			scanf_s("%d", &t);
			if (NextElem_Sq(L, i, t, &e) == 1)
				printf("元素%d的后继为%d\n\n", t, e);
			else
				printf("元素%d无后继\n", t); break;

		case 7:printf("\ni=");
			scanf_s("%d", &i);
			printf("\nx=");
			scanf_s("%d", &e);
			if (ListInsert_Sq(L, i, e) == ERROR)
				printf("i值不合法\n\n");
			else {
				printf("新的线性表为: ");
				ListTraverse_Sq(L);
			}break;

		case 8:printf("\ni=");
			scanf_s("%d", &i);
			if (ListDelete_Sq(&L, i, &e) == ERROR)
				printf("i值不合法\n\n");
			else {
				printf("被删除的第%d个元素的值为%d\n", i, e);
				printf("新的线性表为:");
				ListTraverse_Sq(L);
			} break;

		case 9:ListTraverse_Sq(L); break;

		case 10:ClearList_Sq(&L);
			printf("清空线性表成功,线性表长度是%d \n\n", L.length); break;
		
		case 11:printf("\ni=");
			scanf_s("%d", &i);
			printf("\nx=");
			scanf_s("%d", &cur_e);
			t=AlterElem_Sq(L, i,e,cur_e );
			if (t == ERROR) {
				printf("i值不合法");
			}
			else {
				printf("新的线性表为：\n");
				ListTraverse_Sq(L);
			}break;

		case 12:printf("删除表中最小值，由尾元素代替。\n");
			DeleteMinElem_Sq(L, e);
			printf("删除的元素为：%d\n", e);
			ListTraverse_Sq(L);
			break;

		case 13:printf("倒置线性表");
			Convert_Sq(L);
			ListTraverse_Sq(L);
			break;

		case 14:printf("删除指定X\nX=");
			scanf_s("%d", &X);
			DeleteX(L, X);
			ListTraverse_Sq(L);
			printf("新表长度%d",L.length);
			break;

		case 15:printf("删除给定值S与T之间的所有元素S<T\n");
			printf("S=");
			scanf_s("%d", &S);
			printf("T=");
			scanf_s("%d", &T);
			DeleteStoT(L, S, T);
			ListTraverse_Sq(L);
			break;
		case 16: printf("删除大于S小于T的所有元素S<T\n");
			printf("S=");
			scanf_s("%d", &S);
			printf("T=");
			scanf_s("%d", &T);
			DeleteS_T(L, S, T);
			ListTraverse_Sq(L);
			break;

		case 17: printf("暴力去重\n");
			DuplicatesElimination_Violence(L);
			ListTraverse_Sq(L);
			break;

		case 18: printf("排序去重\n");
			DuplicatesElimination_sort(L);
			ListTraverse_Sq(L);
			break;

		case 19:printf("有序表合并合并两表\n");
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
				printf("创建失败");
				break;
			}
			D = CreateList_Sq(&MergeList2);
			if (D == OK) {
				merge_sort(MergeList2, MergeList2, 0, MergeList2.length - 1);
				ListTraverse_Sq(MergeList2);
			}
			else {
				printf("创建失败");
				break;
			}
			 SqList Mergelist=MergeList(MergeList1, MergeList2);
			 ListTraverse_Sq(Mergelist);
			 break;

		case 20:printf("顺序表位置互换\n");
			printf("a数组元素个数");
			scanf_s("%d", &S);
			printf("b数组元素个数");
			scanf_s("%d", &T);
			Reverse(L, 0, S + T-1, L.length);
			Reverse(L, 0, T - 1, L.length);
			Reverse(L, T, S + T - 1, L.length);
			ListTraverse_Sq(L);
			break;

		case 21:printf("查找X,找到X则交换其后置元素,没找到则按序插入顺序表。\n");
			merge_sort(L, L, 0, L.length-1);
			ListTraverse_Sq(L);
			printf("X=");
			scanf_s("%d", &X);
			SearchX(L, X);
			ListTraverse_Sq(L);
			break;

		case 22:printf("顺序表左移p个单位\n");
			int p;
			printf("P=");
			scanf_s("%d", &p);
			LeftTranslation_p(L, p);
			ListTraverse_Sq(L);
			break;

		case 23:printf("生成两个随机长度(0<n,m<1000)的有序顺序表\n");
			SqList ROL1;
			SqList ROL2;
			InitList_Sq(&ROL1);
			InitList_Sq(&ROL2);
			CreatOrderList_sq(ROL1);
			//CreateList_Sq(&ROL1);
			ListTraverse_Sq(ROL1);
			printf("线性表的长度为%d\n", ROL1.length);
			Sleep(1000);
			//CreateList_Sq(&ROL2);
			CreatOrderList_sq(ROL2);
			ListTraverse_Sq(ROL2);
			printf("线性表的长度为%d\n", ROL2.length);
			printf("网络版答案：\n");
			M=M_Search(ROL1, ROL2);
			printf("中位数为：%f\n", M);
			break;

		case 24:printf("数组主元素\n");
			X = MainElem_wangdao(L);
			printf("主元素为：%d", X);
			break;

		case 25:printf("寻找未出现的最小整数\n");
			X = MinIntegerNS(L);
			printf("最小未出现的整数为：%d\n", X);
			break;

		case 40:
			clock_t start, end;
			start = clock();
			merge_sort(L, L, 0, L.length-1);
			end = clock();
			ListTraverse_Sq(L);
			printf("归并排序时间为： %f ms\n", (double)(end - start)*1000 / CLOCKS_PER_SEC);
			break;

		case 50:printf("初始化并填入线性表数据\n");
			InitList_Sq(&L);
			D=CreateList_Sq(&L);
			if(D==OK){
			ListTraverse_Sq(L);
			}
			else {
				break;
			}
			break;

		case 0: printf("操作结束\n"); break;
		default:printf("输入选择出错! \n");
		}
	} while (select != 0);
	DestoryList_Sq(& L);
}
