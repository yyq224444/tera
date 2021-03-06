// Copyright (c) 2015, Baidu.com, Inc. All Rights Reserved
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// Author: Xu Peilin (xupeilin@baidu.com)

#ifndef  TERA_UTILS_T_PRINTER_H
#define  TERA_UTILS_T_PRINTER_H

#include <stdint.h>

#include <string>
#include <vector>

using std::string;

namespace tera {

class TPrinter {
public:
    typedef std::vector<string> Line;
    typedef std::vector<Line> Table;

    TPrinter();
    TPrinter(int cols);
    ~TPrinter();

    bool AddRow(std::vector<string>& cols);

    bool AddRow(int argc, ...);

    bool AddRow(std::vector<int64_t>& cols);

    void Print(bool has_head = true);

    string ToString(bool has_head = true);

    void Reset();

    void Reset(int cols);

    static string RemoveSubString(const string& input,
                                   const string& substr);
private:
    const static int kMaxColWidth = 50;
    int _cols;
    std::vector<int> _col_width;
    Table _table;
};

} // namespace tera
#endif // TERA_UTILS_T_PRINTER_H
