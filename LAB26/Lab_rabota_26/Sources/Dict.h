#pragma once
/*
�������� �������� �������:
INSERT
MEMBER
��������� ������� �������:
CREATE
DESTROY
*/

/* INSERT � ��������� ������� � ���������.
��������� � �������� ������ ���������� ��������.
��� ��������� ���������� �������� � ���������, ��������� �� ����������. */
void Insert(char* word);

/* MEMBER � ��������, �������� �� ��������� ������� ������ ������� ��������� ��� ���. */
int  Member(char* word);

/* CREATE - ������� �������.
���������� ����� ������� ������������� �������. */
void Create();

/* DESTROY - ���������� �������.
���������� ����� ��������� ������������� �������. */
void Destroy();

// ������������ ����� ����� � �������
#define MAX_LEN_WORD 80

