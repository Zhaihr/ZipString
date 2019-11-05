一次公司面试的上机题
文件in.txt中有一行字符串，从in.txt中读取字符串如果字符串中有连续重复字符则将其压缩，例如aaabcccdef，压缩结果abcdef，并且将结果存放到out.txt文件中。
压缩格式：aaabcccdef在文件out.txt中输出结果形式：3ab3cdef




在vs2019中，使用fopen函数会提醒安全问题
解决办法：打开项目–>属性–>C/C++–>预处理器–>预处理器定义，编辑右边输入框加入：_CRT_SECURE_NO_WARNINGS
