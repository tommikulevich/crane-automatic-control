# 📈 Visualization Of Automatic Control System: Crane

> ☣ **Warning:** This project was created for educational purposes only. It may contain non-optimal or outdated solutions.

### 📜 About
A program simulating the operation of the **crane** is presented. It automatically builds a tower consisting of 3 elements: *Square->Triangle->Circle*. This Project was implemented in Visual Studio 2019 using Windows Forms (CRL Project with. Net Framework 4.7.2).

<img src="/_readmeImg/Screen0.png?raw=true 'Crane'" width="500">

### 🎯 How to run?
To run the program and ensure its correct operation, you should:
1. Make sure that Visual Studio 2019 has **C++/CLI support for v142 build tools** installed.
	Help: https://docs.microsoft.com/en-us/cpp/dotnet/dotnet-programming-with-cpp-cli-visual-cpp?view=msvc-160
2. Go to *Project->Project4 Properties->Configuration Properties->Linker->System* and change the value of *SubSystem* to **Windows (/SUBSYSTEM: WINDOWS)**.

<img src="/_readmeImg/Screen1.png?raw=true 'Settings I'" width="500">

3. Go to *Project->Project4 Properties->Configuration Properties->Linker->Advanced* and change the value of *Entry point* to **main**.

<img src="/_readmeImg/Screen2.png?raw=true 'Settings II'" width="500">

4. If errors appear at startup, try to enter the folder with the project, open the settings file of file *FormCrane.resx* and select **Unblock** (if there is such an option).

*Additionally:* if you see an error when you first open the project instead of the form, you must restart Visual Studio.

### 💻 How does it work?
Windows Forms is a pretty nice tool for doing GUI. We have a lot of different settings for window elements, which we do not necessarily have to manually enter into the code. The operation of this program can be determined in several steps:
- Start - display window elements.
- The user presses the **Go!** button
- The program generates blocks.
- The program *in stages* begins the construction of the tower.
- When the tower is built, a message will be displayed.

| Stage        | Visualization | Description                                             |
| :----------: |:------------:| :--------------------------------------------------------|
| **1**        | 🔗 ▶️       | hook moves in the direction of the triangle              |
| **2**        | 🔗 🔽       | hook drops down                                          |
| **3**        | 🔗🔺⏫     | hook (together with the triangle) rises                   |
| **4**        | 🔗🔺⏩     | hook (together with the triangle) moves towards the square |
| **5**        | 🔗🔺⏬     | hook (together with the triangle) falls down               |
| **6**        | 🔗🔼        | hook rises     						|
| **7**        | 🔗▶️        | hook moves in the direction of the circle                |
| **8**        | 🔗🔽        | hook drops down                                          |
| **9**        | 🔗⚫⏫     | hook (together with the circle) rises                     |
| **10**       | 🔗⚫⏩     | hook (together with the circle) moves towards the square   |
| **11**       | 🔗⚫⏬     | hook (together with the circle) falls down                 |
|              |🔗⚫🔺🟥   | end			                                         |

### 💪 Authors
- **Tomash Mikulevich**
- **Igor Malkovskiy**
