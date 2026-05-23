#include <QtTest/QtTest>

#include "projectmodel.h"

class ProjectModelTest : public QObject
{
    Q_OBJECT

private slots:
    void startsEmpty();
    void assignsIncrementalIds();
    void updatesExistingParameter();
    void refusesUnknownParameter();
    void clearResetsIds();
};

void ProjectModelTest::startsEmpty()
{
    ProjectModel model;
    QCOMPARE(model.operationCount(), 0);
    QVERIFY(model.operations().isEmpty());
}

void ProjectModelTest::assignsIncrementalIds()
{
    ProjectModel model;
    const int first = model.addOperation("box", "Box", {{"Length", 10.0}});
    const int second = model.addOperation("cylinder", "Cylinder", {{"Radius", 5.0}});

    QCOMPARE(first, 1);
    QCOMPARE(second, 2);
    QCOMPARE(model.operationCount(), 2);
    QCOMPARE(model.findOperation(first)->type, QString("box"));
    QCOMPARE(model.findOperation(second)->label, QString("Cylinder"));
}

void ProjectModelTest::updatesExistingParameter()
{
    ProjectModel model;
    const int id = model.addOperation("box", "Box", {{"Length", 10.0}});

    QVERIFY(model.setOperationParameter(id, "Length", 25.0));
    QCOMPARE(model.findOperation(id)->parameters.first().value.toDouble(), 25.0);
}

void ProjectModelTest::refusesUnknownParameter()
{
    ProjectModel model;
    const int id = model.addOperation("box", "Box", {{"Length", 10.0}});

    QVERIFY(!model.setOperationParameter(id, "Width", 20.0));
    QVERIFY(!model.setOperationParameter(999, "Length", 20.0));
}

void ProjectModelTest::clearResetsIds()
{
    ProjectModel model;
    model.addOperation("box", "Box", {{"Length", 10.0}});
    model.clear();

    QCOMPARE(model.operationCount(), 0);
    QCOMPARE(model.addOperation("cone", "Cone", {{"Height", 30.0}}), 1);
}

QTEST_MAIN(ProjectModelTest)
#include "tst_projectmodel.moc"
