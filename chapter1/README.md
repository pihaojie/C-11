1.1
auto:
原理：基于模板类型推断
不适用场景：
1:无法定义数组，auto a[10];
2:不能用于非静态成员变量 struct F{
                            auto a=1;
                        };
3：无法推导模板参数，F<auto> f;
4：无法用于函数参数，f(auto a),测试时发现只是警告没有报错

decltype(exp):
如 decltypoe(x)y=1,根据表达式x推断y的类型，与=1无关
1：如果 exp 是一个不被括号( )包围的表达式，或者是一个类成员访问表达式，或者是一个单独的变量，那么 decltype(exp) 的类型就和 exp 一致
2：如果 exp 是函数调用，那么 decltype(exp) 的类型就和函数返回值的类型一致。
3：如果 exp 是一个左值，或者被括号( )包围，那么 decltype(exp) 的类型就是 exp 的引用；假设 exp 的类型为 T，那么 decltype(exp) 的类型就是 T&。

decltype与auto区别：
1：auto 并不适用于所有的自动类型推导场景，在某些特殊情况下 auto 用起来非常不方便，甚至压根无法使用，所以 decltype 关键字也被引入到 C++11 中。
2：auto 根据=右边的初始值 value 推导出变量的类型，而 decltype 根据 exp 表达式推导出变量的类型，跟=右边的 value 没有关系。
3：auto 要求变量必须初始化，而 decltype 不要求。