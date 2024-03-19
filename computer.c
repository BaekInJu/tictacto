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
	//1. 컴퓨터는 중앙에 착수한다. (첫번째 착수)
	//2. 착수위치 반대편에 상대방 돌이 없을 경우만 착수한다. (두번째 착수)
	//3. 공격할 수 있으면 공격.(반대편에 내 돌이 있을 때 착수)
	//  공격이 안되면 수비(4가지 경우), 공격도 수비도 안되면 아무데나
	//일단 중복착수 해결부터
	static int turn = 1;  //함수가 종료되어도 남아있도록 static
	srand(time(NULL));

	if (inp == 2) {  // 컴퓨터가 선공일 땐 원래의 알고리즘 적용
		switch (turn) {
		case 1:
			//중앙에 착수
			ip[1][1] = 1;
			turn++;
			return;
			break;
		case 2:
			//반대편에 상대방 돌이 없을 경우만 착수
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
			//공격, 수비, 아무데나
			//공격
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (ip[i][j] == 0 && ip[2 - i][2 - j] == 1) {   //저번주 동작 하지 않은 이유  조건문 오타"(ip[2 - i][2 - j] == 1"에 == 1 부분이 빠져있었음
						ip[i][j] = 1;
						turn++;
						return;
					}
				}
			}
			//수비
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

				//아무데나   
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
	{  //컴퓨터가 후공일 땐 두가지 경우로 나눴다. 사용자가 중앙에 착수를 했을경우, 안했을 경우
		if (ip[1][1] == 2) {  //사용자가 중앙에 착수 한 경우
			switch (turn) {
				//컴퓨터는 첫번째에 무조건 모서리에 착수한다.
				//이유는 가운데에 착수 했을 경우에는 (ㅡ, ㅣ) 처럼 이어지는 라인이 하나밖에 없다.
				//가장자리에 했을땐 (ㄱ, ㄴ)처럼 두 갈래가 있어서 이길확률이 증가한다.
			case 1:
			{
				turn++;
				int a = rand() % 4;
				for (int i = 0; i < 10; i++) {
					printf("%d", a);
				}
				while (1) {
					int a = rand() % 4; //rand()를 통해 총 네곳의 모서리중 한곳에 착수한다.
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
			default:   // 기존 공격 수비 알고리즘 그대로 공격과 수비만 바뀌었다.
				//공격
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
				//수비
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						if (ip[i][j] == 0 && ip[2 - i][2 - j] == 2) {
							ip[i][j] = 1;
							turn++;
							return;
						}
					}
				}

				//아무데나   
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
		else { // 사용자가 중앙에 착수 하지 않았을 경우
			switch (turn) {
			case 1:  //처음에 중앙에 착수한다.
				ip[1][1] = 1;
				turn++;
				return;
			default:  //바로 공격과 수비 알고리즘으로 돌아간다.
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						if (ip[i][j] == 0 && ip[2 - i][2 - j] == 1) {   //저번주 동작 하지 않은 이유  조건문 오타"(ip[2 - i][2 - j] == 1"에 == 1 부분이 빠져있었음
							ip[i][j] = 1;
							turn++;
							return;
						}
					}
				}
				//수비
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

					//아무데나   
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