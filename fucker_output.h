/*
	头文件名字：fucker_output
	开发者：sliperman
	所属工作室：不刘名科创
	版本：0.1.0
	食用方法： 
		#include"fucker_output.h"
		using fucker_io::你要食用的函数名;
	如有问题，请问我
	QQ：798500620
*/

#pragma once
#include <ios>
#include <iostream>

namespace fucker_output {

template<typename _Tp, typename CharT = char>
struct output_sequence {
    void operator()(const _Tp& __x, CharT crg = ' ') const {
        using std::cout;
        auto it = __x.begin();
        if (it == __x.end()) return;
        cout << *it;
        for (++it; it != __x.end(); ++it) {
            cout << crg << *it;
        }
    }
};

template<typename cont>
void ops(const cont& c) {
    using std::cout;
    bool first = true;
    for (const auto& x : c) {
        if (!first) cout << ' ';
        cout << x;
        first = false;
    }
}

template<typename cont>
void ops_ln(const cont& c) {
    ops(c);
    std::cout << '\n';
}


template<typename itera, typename CharT = char>
void output_range(itera fs, itera ls, CharT crg = ' ') {
    using std::cout;
    if (fs == ls) return;
    cout << *fs;
    for (++fs; fs != ls; ++fs) {
        cout << crg << *fs;
    }
}


template<typename xs>
void outputln(const xs& x) {
    std::cout << x << '\n';
}

} // namespace fucker io

