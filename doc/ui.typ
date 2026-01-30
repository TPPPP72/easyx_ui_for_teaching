#import "@preview/touying:0.6.1": *
#import themes.university: *
#import "@preview/cetz:0.4.2"

#import "@preview/numbly:0.1.0": numbly

#show: university-theme.with(
  aspect-ratio: "16-9",
  config-info(
    title: [GUI工作原理],
    subtitle: [Subtitle],
    author: [TPPPP],
    date: datetime.today(),
    institution: [Institution],
  ),
)

== 目录

== 1. 核心架构：主循环 (The Main Loop)

UI 程序不是线性执行完就结束的，而是一个持续运行的#strong[死循环]。它负责监听操作系统信号并驱动渲染。

+ #strong[事件监听：] 捕获鼠标点击、键盘输入、系统缩放。
+ #strong[状态更新：] 根据逻辑修改数据模型。
+ #strong[渲染流水线：] 布局 (Layout) -> 绘制 (Paint) -> 合成 (Composite)。



#strong[核心逻辑：]
```rust
> loop {
>   let event = os::wait_event();
>   ui::handle_input(event);
>   ui::update_animations();
>   if ui::needs_redraw() {
>     window.render();
>   }
> }
```

---

== 2. 层级关系：Window, Page 与 Panel

UI 的组织通常遵循“容器套容器”的递归模式。

=== 核心组件定义
1. #strong[Window (窗口):] 操作系统的顶级句柄，拥有 GPU 渲染上下文。
2. #strong[Page (页面):] 路由单位，通常代表一个完整的业务场景。
3. #strong[Panel (面板/容器):] 布局的基本单元，负责裁剪和对其子元素的定位。

---

== 3. 架构关系图解

通过下图可以看到各组件是如何嵌套与协作的：

#align(center)[
  #cetz.canvas({
    import cetz.draw: *

    // 定义基本尺寸变量，方便调整
    let win-w = 10
    let win-h = 6

    // 1. Window (最底层/最大容器)
    rect((-win-w / 2, -win-h / 2), (win-w / 2, win-h / 2), stroke: 1.5pt + gray, name: "win", fill: white)
    content("win.north-west", [ Window (OS Context) ], anchor: "south-west", padding: .1)

    // 2. Page (稍微缩小一点，表示它是 Window 的内容)
    rect((-4.5, -2.5), (4.5, 2.5), stroke: (dash: "dashed", paint: blue), name: "page")
    content("page.north-east", [ Active Page ], anchor: "south-east", padding: .1, fill: blue)

    // 3. Panels (增加间距)
    // 左侧 Panel
    rect((-4.2, -2.2), (-1.5, 2.2), fill: blue.lighten(90%), stroke: blue.lighten(50%), name: "p1")
    content("p1.center", [ Navigation \ Panel ])

    // 右侧 Panel
    rect((-1.0, -2.2), (4.2, 2.2), fill: orange.lighten(90%), stroke: orange.lighten(50%), name: "p2")
    content("p2.north", [ Content Panel ], anchor: "north", padding: .2)

    // 4. Controls (放在右侧 Panel 内部)
    circle((1.6, 0), radius: 0.7, fill: white, stroke: orange, name: "btn")
    content("btn", [ Button ])

    // 可选：添加简单的层级箭头线
    line("win.west", "page.west", mark: (end: ">", fill: blue), stroke: 0.5pt + blue)
  })
]

---

== 4. 布局与绘制原理

UI 库如何知道按钮该画在哪里？通常经过两个阶段：

=== 阶段 A：Measure (测量)
父容器询问子元素：“你需要多大空间？”
- $W_{#text[available]}, H_{#text[available]} arrow W_{#text[desired]}, H_{#text[desired]}$

=== 阶段 B：Layout (布局)
父容器决定子元素的坐标：
- $(x, y) = f(#text[{Alignment, Margin, Padding}])$

=== 阶段 C：Paint (绘制)
调用绘图接口将像素填充到缓冲区

