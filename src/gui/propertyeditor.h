#ifndef __PROPERTYEDITOR_H__
#define __PROPERTYEDITOR_H__

#include <qobjectlist.h>
#include <qdict.h>
#include <qmap.h>
#include <qwidget.h>
#include <iproperty.h>
#include <pdfoperators.h>

class QScrollView;
class QLabel;
class QStringList;
class QGridLayout;
class QLabel;
class QFrame;

namespace gui {

class Property;
class PropertyModeController;

using namespace pdfobjects;

/** Property editor widget */
class PropertyEditor : public QWidget {
 Q_OBJECT
public:
 PropertyEditor(QWidget *parent=0, const char *name=0);
 virtual ~PropertyEditor();
 void resizeEvent (QResizeEvent *e);
 void clear();
 void commitProperty();
 void checkOverrides();
public slots:
 void unsetObject();
 void setObject(const QString &message);
 void setObject(boost::shared_ptr<IProperty> pdfObject);
 void setObject(const QString &name,boost::shared_ptr<IProperty> pdfObject);
 void setObject(boost::shared_ptr<PdfOperator> pdfOp);
 void update(Property *p);
 void reloadItem();
signals:
 /**
  Signal emitted when any property is modified
  Send property pointer with the signal
  @param prop Pointer to changed property item
 */
 void propertyChanged(IProperty *prop); 
private:
 void sortList(std::vector<std::string> &list);
 void override(bool _showHidden,bool _editReadOnly);
 bool addProperty(const QString &name,boost::shared_ptr<IProperty> value);
 void addProperty(Property *prop,boost::shared_ptr<IProperty> value);
 void deleteLayout();
 void createLayout();
 void fixPropertyHeight(Property *pr);
private:
 /** Number of objects in property editor */
 int nObjects;
 /** Grid holding all property editing widgets*/
 QFrame *grid;
 /** Layout used for the grid */
 QGridLayout *gridl;
 /** Scrollview holding the grid */
 QScrollView *scroll;
 /** List of property names */
 QStringList *list;
 /** Dictionary with property items */
 QDict<Property> *items;
 /** Dictionary with IProperty items */
 QMap<QString,boost::shared_ptr<IProperty> > *props;
 /** Dictionary with Row numbers for proerties */
 QMap<QWidget*,int> rowNum;
 /** Dictionary with labes for properties*/
 QMap<QWidget*,QLabel*> propLabel;
 /** Dictionary with property labels */
 QDict<QLabel> *labels;
 /** PropertyModeController - modecontroller wrapper instance */
 PropertyModeController *mode;
 /** Show hidden properties */
 bool showHidden;
 /** Edit read-only properties */
 bool editReadOnly;
 /** If Dict/Array/IProeprty is being edited, this contain reference to it */
 boost::shared_ptr<IProperty> currentObj;
 /** If PdfOperator is being edited, this contain reference to it */
 boost::shared_ptr<PdfOperator> currentOp;

};

} // namespace gui

#endif
