#include <iostream>
using namespace std;

template <typename T>
class matrix {
	private :
		int n , m ;
		T **values ;
	public :

		matrix() {
			n = 0 ;
			m = 0 ;
			values = 0 ;
		}

		matrix(int rows , int columns) {
			n = rows ;
			m = columns ;
			values = new T*[n] ;
			for(int i = 0 ; i < n ; i++)
				values[i] = new T[m] ;
			for(int i = 0 ; i < n ; i++)
				for(int j = 0 ; j < m ; j++)
					values[i][j] = 0 ;
		}

		void scan() {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    cin >> values[i][j];
                }
            }
		}

		void print() {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    cout << values[i][j] << "   ";
                }
                cout << "\n";
            }
		}

		matrix(matrix const& mat) {
			n = mat.n ;
			m = mat.m ;
			values = new T*[n] ;
			for(int i = 0 ; i < n ; i++)
				values[i] = new T[m] ;
			for(int i = 0 ; i < n ; i++)
				for(int j = 0 ; j < m ; j++)
					values[i][j] = mat.values[i][j] ;
		}

		~matrix() {
			if(values != 0) {
				for(int i = 0 ; i < n ; i++)
					delete[] values[i] ;
				delete[] values ;
			}
		}

		matrix const operator+(matrix const& mat) {
			matrix result(n , m) ;
			for(int i = 0 ; i < n ; i++)
				for(int j = 0 ; j < m ; j++)
					result.values[i][j] = values[i][j] + mat.values[i][j] ;
			return result ;
		}

		matrix const operator*(matrix const& mat) {
			matrix result(n , mat.m) ;
			for(int i = 0 ; i < n ; i++) {
				for(int j = 0 ; j < mat.m ; j++) {
                    result.values[i][j] = 0;
					for(int k = 0 ; k < m ; k++) {
						result.values[i][j] = result.values[i][j] + values[i][k] * mat.values[k][j] ;
					}
				}
			}
			return result ;
		}

		void operator=(matrix const& mat) {
			if(values != 0) {
				for(int i = 0 ; i < n ; i++)
					delete[] values[i] ;
				delete[] values ;
			}
			n = mat.n ;
			m = mat.m ;
			values = new T*[n] ;
			for(int i = 0 ; i < n ; i++)
				values[i] = new T[m] ;
			for(int i = 0 ; i < n ; i++)
				for(int j = 0 ; j < m ; j++)
					values[i][j] = mat.values[i][j] ;
		}

		T& operator()(int i , int j) {
			return values[i][j] ;
		}
};
