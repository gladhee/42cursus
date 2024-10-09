#include <iostream>
#include "Fixed.hpp"
#include <ios>

int main() {
	// subject main
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	// 1. 생성자 테스트
	Fixed c;                // 기본 생성자
	Fixed d(10);            // 정수형 생성자
	Fixed e(42.42f);        // 실수형(float) 생성자
	Fixed f(d);             // 복사 생성자
	Fixed g;                // 복사 대입 연산자 테스트 용
	g = e;                  // 복사 대입 연산자

	std::cout << "c (default) = " << c << std::endl;
	std::cout << "d (int 10) = " << d << std::endl;
	std::cout << "e (float 42.42) = " << e << std::endl;
	std::cout << "f (copy of d) = " << f << std::endl;
	std::cout << "g (copy of e) = " << g << std::endl;

	// 2. 산술 연산자 테스트
	Fixed h = d + e; // 10 + 42.42
	Fixed i = e - d; // 42.42 - 10
	Fixed j = d * e; // 10 * 42.42
	Fixed k = e / d; // 42.42 / 10

	std::cout << "h (d + e) = " << h << std::endl;
	std::cout << "i (e - d) = " << i << std::endl;
	std::cout << "j (d * e) = " << j << std::endl;
	std::cout << "k (e / d) = " << k << std::endl;

	// 3. 전위/후위 증가/감소 연산자 테스트
	Fixed l(5.5f);
	std::cout << "l = " << l << std::endl;

	std::cout << "++l = " << ++l << std::endl;  // 전위 증가
	std::cout << "l++ = " << l++ << std::endl;  // 후위 증가
	std::cout << "l after l++ = " << l << std::endl;

	std::cout << "--l = " << --l << std::endl;  // 전위 감소
	std::cout << "l-- = " << l-- << std::endl;  // 후위 감소
	std::cout << "l after l-- = " << l << std::endl;

	// 4. 비교 연산자 테스트
	Fixed m(10);
	Fixed n(42.42f);

	std::cout << std::boolalpha;  // true/false 값을 문자열로 출력
	std::cout << "m > n: " << (m > n) << std::endl;  // false
	std::cout << "m < n: " << (m < n) << std::endl;  // true
	std::cout << "m >= n: " << (m >= n) << std::endl;  // false
	std::cout << "m <= n: " << (m <= n) << std::endl;  // true
	std::cout << "m == n: " << (m == n) << std::endl;  // false
	std::cout << "m != n: " << (m != n) << std::endl;  // true

	// 5. min/max 함수 테스트
	Fixed o(10);
	Fixed p(20);

	std::cout << "Min between o and p: " << Fixed::min(o, p) << std::endl;
	std::cout << "Max between o and p: " << Fixed::max(o, p) << std::endl;

	const Fixed q(30);
	const Fixed r(40);

	std::cout << "Const Min between q and r: " << Fixed::min(q, r) << std::endl;
	std::cout << "Const Max between q and r: " << Fixed::max(q, r) << std::endl;

	// 6. 실수 변환 테스트
	std::cout << "d as float: " << d.toFloat() << std::endl;
	std::cout << "e as int: " << e.toInt() << std::endl;

	return 0;
}
