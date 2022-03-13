#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <random>
#include<math.h>


typedef int ElemType;
typedef int Status;
typedef double Double;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define LIST_INIT_SIZE 100
#define	LISTINCREMENT 10
typedef struct {
	ElemType* elem;
	int length;
	int listsize;
}SqList;
//初始化
Status InitList_Sq(SqList* L) {
	(*L).elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!(*L).elem) exit(OVERFLOW);
	(*L).length = 0;
	(*L).listsize = LIST_INIT_SIZE;
}

Status CreateList_Sq(SqList* L) {
	int i, n; 
	ElemType* newbase;
	printf("请输入线性表长度\nn=");
	scanf_s("%d", &n);
	(*L).length = n;
	if ((*L).length*LISTINCREMENT >= (*L).listsize) {
		newbase = (ElemType*)realloc((*L).elem, (LISTINCREMENT) * sizeof(ElemType)*n);
		if (!newbase) {
			exit(OVERFLOW);
		}
		(*L).elem = newbase;
		(*L).listsize = LISTINCREMENT*n;
	}
	//(*L).length = n;
	printf("随机线性表填入1,指定线性表请填入0\n");
	int a;
	scanf_s("%d", &a);
	if (a == 1) {
		time_t t;
		srand(time(&t));
		for (i = 0; i < n; i++) {
			(*L).elem[i] = rand()%50;
		}
		return OK;
	}
	else if(a==0) {
		printf("\n请输入线性表L：\n");
		for (i = 0; i < n; i++) {

			scanf_s("%d", &((*L).elem[i]));
		}
		return OK;
	}
	else
	{
		printf("输入错误\n");
		return ERROR;
	}
}
Status DestoryList_Sq(SqList* L) {
	if ((*L).elem) {
		free((*L).elem);
	}
	return OK;
}
Status ClearList_Sq(SqList* L) {
	(*L).length = 0;
	return OK;
}
Status ListEmpty_Sq(SqList L) {
	if (L.length == 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}
Status ListLength_Sq(SqList L) {
	return(L.length);
}
Status GetElem_Sq(SqList L, int i, ElemType *e) {
	if (i<1 || i>L.length) {
		return ERROR;
	}
		*e = L.elem[i - 1];
		return OK;
}
Status LocateElem_Sq(SqList L, int e) {
	int i;
	for (i = 1; i <= L.length+1; i++) {
		if (L.elem[i - 1] == e) {
			return i;
		}
	}
}
Status PriorElem_Sq(SqList L, ElemType cur_e, ElemType* pre_e) {
	int i = LocateElem_Sq(L, cur_e);
	if (i == 1 || i > ListLength_Sq(L)) {
		return 0;
	}
	*pre_e = L.elem[i - 2];
	return OK;
}
Status NextElem_Sq(SqList L,int i,ElemType cur_e,ElemType*next_e) {
	i = LocateElem_Sq(L, cur_e);
	if (i== ListLength_Sq(L) || i > ListLength_Sq(L)) {
		return 0;
	}
	*next_e = L.elem[i];
	return OK;
}
Status ListInsert_Sq(SqList &L, int i, ElemType e) {
	ElemType* newbase,  p,  q;
	if (i<1 || i>L.length + 1) {
		return ERROR;
	}
	if (L.length >= L.listsize) {
		newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) {
			exit(OVERFLOW);
		}
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	for (int j = L.length; j >= i; j--) {
		L.elem[j] = L.elem[j - 1];
	}
	L.elem[i - 1] = e;
	++L.length;
	return	OK;
}
Status ListDelete_Sq(SqList* L, int i, ElemType* e) {
	ElemType* p, * q;
	if (i<1 || i>(*L).length) {
		return ERROR;
	}
	p = &((*L).elem[i - 1]);
	*e = *p;
	q = (*L).elem + (*L).length - 1;
	for (++p; p <= q; p++) {
		*(p - 1) = *p;
	}
		--(*L).length;
		return OK;
}
Status ListTraverse_Sq(SqList L){
	printf("线性表为：\n");
	for (int i = 0; i<L.length; i++) {
		if (i%10 == 0) {
			printf("\n");
		}
		printf("%4d ", (L.elem[i]));
	}
	printf("\n\n");
	return OK;
}
Status AlterElem_Sq(SqList& L,int i,ElemType &e,ElemType cur_e) {
	if (GetElem_Sq(L, i, &e)==ERROR) {
		return ERROR;
	}else{
		L.elem[i - 1] = cur_e;
		return OK;
	}
}
Status DeleteMinElem_Sq(SqList& L, ElemType& e) {
	if (L.length == 0) {
		return ERROR;
	}
	e = L.elem[0];
	int pos = 0;
	for (int i = 0; i < L.length; i++) {
		if (e > L.elem[i]) {
			e = L.elem[i];
			pos = i;
		}
	}
	L.elem[pos] = L.elem[L.length-1];
	L.length--;
	return OK;
}
Status Convert_Sq(SqList& L) {
	ElemType temp;
	for (int i = 0; i < L.length / 2; i++) {
		temp = L.elem[i];
		L.elem[i] = L.elem[L.length - 1 - i];
		L.elem[L.length - 1 - i]=temp;
	}
	return OK;
}
Status DeleteX(SqList& L, ElemType X) {
	int k = 0;
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] != X) {
			L.elem[k] = L.elem[i];
			k++;
		}
	}
	if (k == L.length) {
		printf("表中无X对应的值");
	}
	L.length = k;
	return OK;
}
Status DeleteStoT(SqList& L, ElemType s, ElemType t) {
	int i, j;
	if (s >= t || L.length == 0) {
		printf("数据错误");
		return FALSE;
	}
	for (i = 0; i<L.length && L.elem[i]<s;i++);
	if (i >= L.length) {
		return FALSE;
	}
	for (j = i; j < L.length && L.elem[j] <= t; j++);
	for (i, j; j < L.length; i++, j++) {
		L.elem[i] = L.elem[j];
	}
	L.length = i;
	return OK;
}
Status InitTempList_Sq(SqList& L, SqList L1) {
	L.elem = (ElemType*)malloc(L1.length * LISTINCREMENT * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);
	L.length = L1.length;
	L.listsize = L1.length * sizeof(ElemType);
}
Status merge(SqList L1, SqList L2, int left, int mid, int right) {
	int i, j, k;
	i = left;
	j = mid + 1;
	k = left;
	while (i <= mid && j <= right) {
		if (L1.elem[i] <= L1.elem[j]) {
			L2.elem[k] = L1.elem[i];
			i++;
			k++;
		}
		else {
			L2.elem[k] = L1.elem[j];
			j++;
			k++;
		}
	}
		while (i <= mid) {
			L2.elem[k++] = L1.elem[i++];
		}
		while (j <= right) {
			L2.elem[k++] = L1.elem[j++];
		}
	return OK;
}
Status merge_sort(SqList L1,SqList L2, int left, int right) {
	int mid;
	SqList LTemp;
	InitTempList_Sq(LTemp, L1);
	if (left == right) {
		L2.elem[left] = L1.elem[right];
	}
	else {
		mid = (left + right) / 2;
		merge_sort(L1, LTemp, left, mid);
		merge_sort(L1, LTemp, mid + 1, right);
		merge(LTemp,L2,  left, mid, right);
		
	}
	DestoryList_Sq(&LTemp);
	return OK;
}
Status DeleteS_T(SqList &L, int S, int T) {
	if (S > T||L.length==0) {
		printf("S、T值不合法，或顺序表为空\n");
		return ERROR;
	}
	int k=0;
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] >= S && L.elem[i] <= T) {
			k++;
		}
		else {
			L.elem[i - k] = L.elem[i];
		}
	}
	L.length -= k;
	return OK;
}
Status DuplicatesElimination_Violence(SqList &L) {
	for (int i = 0; i < L.length; i++) {
		int k=0;//记录重复个数
		for (int j = i+1; j < L.length; j++) {//从i+1遍历顺序表
			if (L.elem[i] == L.elem[j]) {//判断重复
				k++;
			}
			else {
				L.elem[j - k] = L.elem[j];//元素前移
			}
		}
		L.length -= k;//表长度减少
	}
	return OK;
}
SqList MergeList(SqList L1, SqList L2) {
	SqList M;
	InitList_Sq(&M);
	M.elem = (ElemType*)malloc((LISTINCREMENT)*(L1.length + L2.length) * sizeof(ElemType));
	if (!M.elem) exit(OVERFLOW);
	M.length = L1.length + L2.length;
	M.listsize = (L1.length + L2.length) * sizeof(ElemType);
	for (int i = 0; i < L1.length; i++) {
		M.elem[i] = L1.elem[i];
	}
	for (int i =0; i < M.length; i++) {
		M.elem[i+L1.length] = L2.elem[i];
	}
	merge_sort(M, M, 0, M.length-1);
	return M;
}
Status DuplicatesElimination_sort(SqList& L) {
	merge_sort(L, L, 0, L.length - 1);
	int i, j;
	for (i=0, j=1; j < L.length; j++) {
		if (L.elem[i] != L.elem[j]) {
			L.elem[++i] = L.elem[j];
		}
	}
		L.length = i+1;
		return OK;
}
Status InitTempList(SqList& L) {
	L.elem = (ElemType*)malloc(LISTINCREMENT * sizeof(ElemType));
	if (!L.elem) {
		exit(OVERFLOW);
	}
	L.length = 1;
	L.listsize = LISTINCREMENT;
}
Status Reverse(SqList& L, int left, int right, int listsize) {
	if (left >= right || right >= listsize) {
		return ERROR;
	}
	int mid = (right + left) / 2;
	for (int i = 0; i <= mid - left; i++) {
		int temp;
		temp = L.elem[left+i];
		L.elem[left + i] = L.elem[right - i];
		L.elem[right - i] = temp;
	}
	return OK;
}
Status SearchX(SqList& L, int X) {
	int low = 0, high = L.length-1,mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (L.elem[mid] == X) {
			break;
		}
		else if(L.elem[mid]<X) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	if (L.elem[mid] == X && mid != L.length - 1) {
		ElemType temp;
		temp = L.elem[mid];
		L.elem[mid] = L.elem[mid + 1];
		L.elem[mid + 1] = temp;

	}
	if (low > high) {
		int i;
		for (i = L.length - 1; i > high; i--) {
			L.elem[i + 1] = L.elem[i];
		}
		L.elem[i + 1] = X;
		L.length += 1;
	}
	
	return OK;
}
Status Reverse1(SqList& L, int from, int to) {
	int i;
	ElemType temp;
	for (i = 0; i <= (to - from) / 2; i++) {
		temp = L.elem[from + i];
		L.elem[from + i] = L.elem[to - i];
		L.elem[to - i] = temp;
	}
	return OK;
}
Status LeftTranslation_p(SqList& L, int p) {
	if (p > L.length) {
		return ERROR;
	}
	Reverse1(L, 0, p - 1);
	Reverse1(L, p, L.length - 1 );
	Reverse1(L, 0, L.length - 1);
	return OK;
}
Status CreatOrderList_sq(SqList& L) {
	time_t t;
	srand(time(&t));
	ElemType* newbase;
	int n = rand()%1000;
	L.length = n;
	if (L.length * LISTINCREMENT >= L.listsize) {
		newbase = (ElemType*)realloc(L.elem, (LISTINCREMENT) * sizeof(ElemType) * n);
		if (!newbase) {
			exit(OVERFLOW);
		}
		L.elem = newbase;
		L.listsize = LISTINCREMENT * n;
	}
	ElemType r = 0;
	for (int i = 0; i < L.length ; i++) {
		r =r+ rand()%50;
		L.elem[i] = r;
	}
	return OK;
}
Status max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}
Status min(int a, int b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}
Double M_Search(SqList &ROL1, SqList &ROL2) {
	int m = ROL1.length;
	int n = ROL2.length;
	if (m > n) {
		return M_Search(ROL2, ROL1);
	}
	int iMin = 0, iMax = m;
	while (iMin <= iMax) {
		int i = (iMin + iMax) / 2;
		int j = (m + n + 1) / 2 - i;
		if (j != 0 && i != m && ROL2.elem[j - 1] > ROL1.elem[i]) {
			iMin = i + 1;
		}
		else if (i != 0 && j != n && ROL1.elem[i - 1] > ROL2.elem[j]) {
			iMax = i - 1;
		}
		else {
			int maxLeft = 0;
			if (i == 0) {
				maxLeft = ROL2.elem[j - 1];
			}
			else if (j == 0) {
				maxLeft = ROL1.elem[i - 1];
			}
			else {
				maxLeft = max(ROL1.elem[i - 1], ROL2.elem[j - 1]);
			}
			if ((m + n) % 2 == 1) {
				return maxLeft;
			}
			int minRight = 0;
			if (i == m) {
				minRight = ROL2.elem[j];
			}
			else if (j == n) {
				minRight = ROL1.elem[i];
			}
			else {
				minRight = min(ROL2.elem[j], ROL1.elem[i]);
			}
			return (maxLeft + minRight) / 2.0;
		}
	}
}


Status MainElem_wangdao(SqList L) {
	int n = L.length;
	int c, i, count = 1;
	c = L.elem[0];
	for (i = 0; i < n; i++) {
		if (L.elem[i] == c) {
			count++;
		}
		else {
			if (count > 0) {
				count--;
			}
			else {
				c = L.elem[i];
				count = 1;
			}
		}
	}
	if (count > 0) {
		for (i = count = 0; i < n; i++) {
			if (L.elem[i] == c) {
				count++;
			}
		}
	}
	if (count > n / 2) {
		return c;
	}
	else {
		return -1;
	}
}
Status MinIntegerNS(SqList L) {
	int n = L.length;
	int i;
	ElemType* B;
	B = (ElemType*)malloc(sizeof(ElemType) * n);
	memset(B, 0, sizeof(ElemType) * n);
	for (i = 0; i < n; i++) {
		if (L.elem[i] > 0 && L.elem[i] < n) {
			B[L.elem[i] - 1] = 1;
		}
	}
	for (i = 0; i < n; i++) {
		if (B[i] == 0) {
			break;
		}
	}
	return i + 1;
}
