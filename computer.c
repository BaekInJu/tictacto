#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void computer(int(*ip)[3], int inp) {  //ip ==> board
	//for (int i = 0; i < 3; i++) {
	//	for (int j = 0; j < 3; j++) {
	//		if (ip[i][j] == 0) {
	//			ip[i][j] = 1;
	//			return;
	//		}
	//	}
	//}
	//1. ��ǻ�ʹ� �߾ӿ� �����Ѵ�. (ù��° ����)
	//2. ������ġ �ݴ��� ���� ���� ���� ��츸 �����Ѵ�. (�ι�° ����)
	//3. ������ �� ������ ����.(�ݴ��� �� ���� ���� �� ����)
	//  ������ �ȵǸ� ����(4���� ���), ���ݵ� ���� �ȵǸ� �ƹ�����
	//�ϴ� �ߺ����� �ذ����
	static int turn = 1;  //�Լ��� ����Ǿ �����ֵ��� static
	srand(time(NULL));

	if (inp == 2) {  // ��ǻ�Ͱ� ������ �� ������ �˰��� ����
		switch (turn) {
		case 1:
			//�߾ӿ� ����
			ip[1][1] = 1;
			turn++;
			return;
			break;
		case 2:
			//�ݴ��� ���� ���� ���� ��츸 ����
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (ip[i][j] == 0 && ip[2 - i][2 - j] != 2) {
						ip[i][j] = 1;
						turn++;
						return;
					}
				}
			}
			break;
		default:
			//����, ����, �ƹ�����
			//����
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (ip[i][j] == 0 && ip[2 - i][2 - j] == 1) {   //������ ���� ���� ���� ����  ���ǹ� ��Ÿ"(ip[2 - i][2 - j] == 1"�� == 1 �κ��� �����־���
						ip[i][j] = 1;
						turn++;
						return;
					}
				}
			}
			//����
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					switch (i) {
					case 0:
						if (ip[0][0] == 2 && ip[0][1] == 2) {
							ip[0][2] = 1;
							return;
						}
						if (ip[0][1] == 2 && ip[0][2] == 2) {
							ip[0][0] = 1;
							return;
						}
						if (ip[0][0] == 2 && ip[0][2] == 2) {
							ip[0][1] = 1;
							return;
						}
					case 2:
						if (ip[2][0] == 2 && ip[2][1] == 2) {
							ip[2][2] = 1;
							return;
						}
						if (ip[2][1] == 2 && ip[2][2] == 2) {
							ip[2][0] = 1;
							return;
						}
						if (ip[2][0] == 2 && ip[2][2] == 2) {
							ip[2][1] = 1;
							return;
						}
						switch (j) {
						case 0:
							if (ip[0][0] == 2 && ip[1][0] == 2) {
								ip[2][0] = 1;
								return;
							}
							if (ip[1][0] == 2 && ip[2][0] == 2) {
								ip[0][0] = 1;
								return;
							}
							if (ip[0][0] == 2 && ip[2][0] == 2) {
								ip[1][0] = 1;
								return;
							}
						case 2:
							if (ip[0][2] == 2 && ip[1][2] == 2) {
								ip[2][2] = 1;
								return;
							}
							if (ip[1][2] == 2 && ip[2][2] == 2) {
								ip[0][2] = 1;
								return;
							}
							if (ip[0][2] == 2 && ip[2][2] == 2) {
								ip[1][2] = 1;
								return;
							}
						}
					}
				}

				//�ƹ�����   
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						if (ip[i][j] == 0) {
							ip[i][j] = 1;
							return;
						}
					}
				}
				break;
			}
		}
	}
	else
	{  //��ǻ�Ͱ� �İ��� �� �ΰ��� ���� ������. ����ڰ� �߾ӿ� ������ �������, ������ ���
		if (ip[1][1] == 2) {  //����ڰ� �߾ӿ� ���� �� ���
			switch (turn) {
				//��ǻ�ʹ� ù��°�� ������ �𼭸��� �����Ѵ�.
				//������ ����� ���� ���� ��쿡�� (��, ��) ó�� �̾����� ������ �ϳ��ۿ� ����.
				//�����ڸ��� ������ (��, ��)ó�� �� ������ �־ �̱�Ȯ���� �����Ѵ�.
			case 1:
			{
				turn++;
				int a = rand() % 4;
				for (int i = 0; i < 10; i++) {
					printf("%d", a);
				}
				while (1) {
					int a = rand() % 4; //rand()�� ���� �� �װ��� �𼭸��� �Ѱ��� �����Ѵ�.
					if (a == 0) {
						ip[0][0] = 1;
					    return;
					}
					else if (a == 1) {
						ip[0][2] == 1;
						return;
					}
					else if (a == 2) {
						ip[2][0] == 1;
						return;
					}
					else {
						ip[2][2] == 1;
						return;
					}
				}
				break;
			}
			default:   // ���� ���� ���� �˰��� �״�� ���ݰ� ���� �ٲ����.
				//����
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						switch (i) {
						case 0:
							if (ip[0][0] == 1 && ip[0][1] == 1 && ip[0][2] == 0) {
								ip[0][2] = 1;
								return;
							}
							if (ip[0][1] == 1 && ip[0][2] == 1 && ip[0][0] == 0) {
								ip[0][0] = 1;
								return;
							}
							if (ip[0][0] == 1 && ip[0][2] == 1 && ip[0][1] == 0) {
								ip[0][1] = 1;
								return;
							}
						case 2:
							if (ip[2][0] == 1 && ip[2][1] == 1 && ip[2][2] == 0) {
								ip[2][2] = 1;
								return;
							}
							if (ip[2][1] == 1 && ip[2][2] == 1 && ip[2][0] == 0) {
								ip[2][0] = 1;
								return;
							}
							if (ip[2][0] == 1 && ip[2][2] == 1 && ip[2][1] == 0) {
								ip[2][1] = 1;
								return;
							}
							switch (j) {
							case 0:
								if (ip[0][0] == 1 && ip[1][0] == 1 && ip[2][0] == 0) {
									ip[2][0] = 1;
									return;
								}
								if (ip[1][0] == 1 && ip[2][0] == 1 && ip[0][0] == 0) {
									ip[0][0] = 1;
									return;
								} 
								if (ip[0][0] == 1 && ip[2][0] == 1 && ip[1][0] == 0) {
									ip[1][0] = 1;
									return;
								}
							case 2:
								if (ip[0][2] == 1 && ip[1][2] == 1 && ip[2][2] == 0) {
									ip[2][2] = 1;
									return;
								}
								if (ip[1][2] == 1 && ip[2][2] == 1 && ip[0][2] == 0) {
									ip[0][2] = 1;
									return;
								}
								if (ip[0][2] == 1 && ip[2][2] == 1 && ip[1][2] == 0) {
									ip[1][2] = 1;
									return;
								}
							}
						}
					}
				}
				//����
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						if (ip[i][j] == 0 && ip[2 - i][2 - j] == 2) {
							ip[i][j] = 1;
							turn++;
							return;
						}
					}
				}

				//�ƹ�����   
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						if (ip[i][j] == 0) {
							ip[i][j] = 1;
							return;
						}
					}
				}
				break;
			}
		}
		else { // ����ڰ� �߾ӿ� ���� ���� �ʾ��� ���
			switch (turn) {
			case 1:  //ó���� �߾ӿ� �����Ѵ�.
				ip[1][1] = 1;
				turn++;
				return;
			default:  //�ٷ� ���ݰ� ���� �˰������� ���ư���.
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						if (ip[i][j] == 0 && ip[2 - i][2 - j] == 1) {   //������ ���� ���� ���� ����  ���ǹ� ��Ÿ"(ip[2 - i][2 - j] == 1"�� == 1 �κ��� �����־���
							ip[i][j] = 1;
							turn++;
							return;
						}
					}
				}
				//����
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						switch (i) {
						case 0:
							if (ip[0][0] == 2 && ip[0][1] == 2) {
								ip[0][2] = 1;
								return;
							}
							if (ip[0][1] == 2 && ip[0][2] == 2) {
								ip[0][0] = 1;
								return;
							}
							if (ip[0][0] == 2 && ip[0][2] == 2) {
								ip[0][1] = 1;
								return;
							}
						case 2:
							if (ip[2][0] == 2 && ip[2][1] == 2) {
								ip[2][2] = 1;
								return;
							}
							if (ip[2][1] == 2 && ip[2][2] == 2) {
								ip[2][0] = 1;
								return;
							}
							if (ip[2][0] == 2 && ip[2][2] == 2) {
								ip[2][1] = 1;
								return;
							}
							switch (j) {
							case 0:
								if (ip[0][0] == 2 && ip[1][0] == 2) {
									ip[2][0] = 1;
									return;
								}
								if (ip[1][0] == 2 && ip[2][0] == 2) {
									ip[0][0] = 1;
									return;
								}
								if (ip[0][0] == 2 && ip[2][0] == 2) {
									ip[1][0] = 1;
									return;
								}
							case 2:
								if (ip[0][2] == 2 && ip[1][2] == 2) {
									ip[2][2] = 1;
									return;
								}
								if (ip[1][2] == 2 && ip[2][2] == 2) {
									ip[0][2] = 1;
									return;
								}
								if (ip[0][2] == 2 && ip[2][2] == 2) {
									ip[1][2] = 1;
									return;
								}
							}
						}
					}

					//�ƹ�����   
					for (int i = 0; i < 3; i++) {
						for (int j = 0; j < 3; j++) {
							if (ip[i][j] == 0) {
								ip[i][j] = 1;
								return;
							}
						}
					}
					break;
				}
			}
		}
	}
}