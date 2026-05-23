# DoidsCAD Laboratory Project

Мини-САПР на C++/Qt Widgets и OpenCascade Technology (OCCT). Проект демонстрирует параметрическое моделирование, историю операций, GUI, импорт и экспорт STEP, тестовый каркас и подготовку документации Doxygen.

## Возможности

- система сборки CMake;
- GUI на Qt Widgets;
- 3D-видовой экран OpenCascade;
- примитивы: box, cylinder, cone;
- операции истории: fillet, fuse, cut;
- абсолютное и относительное позиционирование;
- импорт и экспорт инженерных данных STEP;
- дерево операций и редактор параметров;
- тесты для модели операций;
- Doxygen-документация;
- шаблон GitHub Actions.

## Быстрый запуск

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DOpenCASCADE_DIR=/path/to/opencascade/cmake
cmake --build build --config Release
./build/DoidsCAD
```

На Windows вместо `/path/to/opencascade/cmake` укажите каталог с `OpenCASCADEConfig.cmake`, например `C:/OCCT/occt-vc14-64/cmake`.

## Тесты

```bash
cmake -S . -B build -DBUILD_TESTING=ON -DOpenCASCADE_DIR=/path/to/opencascade/cmake
cmake --build build
ctest --test-dir build --output-on-failure
```

## Doxygen

```bash
doxygen Doxyfile
```

HTML-документация будет создана в `docs/doxygen/html/index.html`.
