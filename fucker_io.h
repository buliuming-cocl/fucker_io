#ifndef FUCKER_IO_H
#define FUCKER_IO_H

#include "fucker_input.h"
#include "fucker_output.h"

/*
此头文件为fucker_input与fucker_output的共同包含版 
食用方法同上面两个，只不过要包含的头文件换成
#include "fucker_io.h" 
祝你用这个库写出改变世界的程序 
作者：sliperman
制作日期：2026/7/13 
*/

namespace fucker_io {
    // fucker_input
    using fucker_input::ips;
    using fucker_input::input_range;
    using fucker_input::input_nt;
    using fucker_input::input_cus;

    // fucker_output
    using fucker_output::ops;
    using fucker_output::ops_ln;
    using fucker_output::output_range;
    using fucker_output::outputln;
} // namespace fucker_io

#endif // FUCKER_IO_H
