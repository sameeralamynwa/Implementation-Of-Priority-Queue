				#include <bits/stdc++.h>
								
				using namespace std;
				
				class PriorityQueue{
					
					public:
					
					int size;
					
					vector <int> A;
					
					void init(void){
						
						cout << "Enter the size and the array you want to build heap for\n";
						cin >> size;
						
					}
					
					void input(void){
						
						for(int i = 0; i < size; i++){
							int x;
							cin >> x;
							A.push_back(x);
						}
						
					}
					
					int read_max(void){
						return A[0];
					}
					
					int extract_max(void){
						int M = A[0];
						
						swap(A[0], A[size - 1]);
						size--;
						heapify(0);
												
						return M;
					}
					
					void insert(int key){
						A[size] = key;

						int current = size;
						
						while(current > 0 && A[(current - 1) / 2] < A[current]){
							swap(A[(current - 1) / 2], A[current]);
							current = (current - 1) / 2;
						}

						size++;
					}
					
					void increase_key(int index, int key){
						if(A[index] > key){
							cout << "Key should be greater than the value\n";
							return;
						}
						A[index] = key;
						
						int current = index;
						
						while(current > 0 && A[(current - 1) / 2] < A[current]){
							swap(A[(current - 1) / 2], A[current]);
							current = (current - 1) / 2;
						}
						
					}
					
					void heapify(int index){
						
						int greatest = index;
						
						if(A[greatest] < A[2 * index + 1] && 2 * index + 1 < size){
							greatest = 2 * index + 1;
						}
						
						if(A[greatest] < A[2 * index + 2] && 2 * index + 2 < size){
							greatest = 2 * index + 2;
						}
												
						if(greatest != index){
							swap(A[greatest], A[index]);
							heapify(greatest);
						}
						
					}
					
				}P;
				
				void solve(void){
					P.init();
					P.input();
					for(int i = P.size / 2 - 1; i >= 0; i--){
						P.heapify(i);
					}

					P.increase_key(1, 7);
					P.insert(9);
					
					cout << P.read_max() << endl;
					cout << P.extract_max() << endl;
					cout << P.read_max() << endl;
					cout << P.extract_max() << endl;
					cout << P.extract_max() << endl;
				}
				
				signed main() {
				int t = 1;
				while(t--){
				    solve();
				}	
				
				    return 0;
				}
