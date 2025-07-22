#include <stdio.h>

void calculate_the_maximum(int n, int k) {
  int m_b = 2;
  int m_and = 0, m_or = 0, m_xor = 0;
  for (int a = 1; a <= n-1; a++) {
    for (int b = m_b; b <= n; b++) {
        int and = a & b;
        int or = a | b;
        int xor = a ^ b;
        
        if (and > m_and && and < k) {
            m_and = and;
        }
        if (or > m_or && or < k) {
            m_or = or;
        }
        if (xor > m_xor && xor < k) {
            m_xor = xor;
        }
        // printf("a = %d, b = %d; a&b = %d; a|b = %d; a^b = %d\n", a, b, m_and, m_or, m_xor);
    }
    m_b++;
  }
  
  printf("%d\n%d\n%d", m_and, m_or, m_xor);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}