# FaceSentinel

**FaceSentinel** is a C++ + OpenCV-based privacy utility that uses your webcam to detect faces in real-time. It automatically locks your Windows screen if it detects more than one face — protecting your screen from shoulder surfing in public or shared environments.

---

## ✨ Features

* 📹 **Real-time Face Detection** using OpenCV Haar Cascade
* ✅ **Live Face Count Displayed** on screen
* ⛔️ **Auto-Lock Screen** with `LockWorkStation()` if a second face is detected
* 📊 **Green Bounding Boxes** around detected faces
* ⏳ **3-second Grace Period** before locking to allow reaction time

---

## 📁 Prerequisites

Make sure the following are installed before building or running:

* A C++17 compatible compiler (Visual Studio recommended)
* OpenCV (version 4.x preferred)
* Git
* CMake (if using cross-platform build)

---

## 📆 Clone & Run

### Step 1: Clone the Repository

```bash
git clone https://github.com/tabrejansary/FaceSentinel.git
cd FaceSentinel
```

### Step 2: Open in Visual Studio (Windows Only)

1. Open Visual Studio
2. Create a new **Empty Project**
3. Add the files from the repo (`.cpp`) to the project
4. Set **C++17** standard in project properties
5. Link OpenCV:

   * Go to `Project Properties`
   * Under **C/C++ > General > Additional Include Directories**: Add path to `OpenCV/include`
   * Under **Linker > General > Additional Library Directories**: Add path to `OpenCV/x64/vcXX/lib`
   * Under **Linker > Input > Additional Dependencies**: Add `opencv_world4xx.lib`

### Step 3: Place the Haar Cascade XML

Download the Haar Cascade model:

```bash
https://github.com/opencv/opencv/blob/master/data/haarcascades/haarcascade_frontalface_default.xml
```

Save it in the project root directory.

### Step 4: Build & Run

Build the project and run it.

Press **ESC key** anytime to quit the application.

---

## ⚖️ How It Works

```cpp
facedetect.detectMultiScale(img, faces, 1.3, 5);
```

* `1.3` = scale factor (image shrink rate)
* `5` = minimum neighbors (higher = stricter face detection)

If `faces.size() > 1`, the system assumes a second person is visible and executes:

```cpp
LockWorkStation();
```

Which immediately locks your screen.

---

## 🔧 Future Improvements

* AI-based eye tracking
* Auto-blur screen before lock
* Face recognition to allow specific users
* Cross-platform support (Linux/Mac)

---

## 🚀 Author

Developed by [Tabrej Ansary](https://github.com/tabrejansary)

Feel free to fork, star, or contribute to the project!

---

## ⚠️ Disclaimer

This is a demo utility and **not meant for enterprise security use**. Use responsibly!
