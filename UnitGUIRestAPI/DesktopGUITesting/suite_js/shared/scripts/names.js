// See the chapter 'Script-Based Object Map API' in the Squish manual for
// documentation of the functionality offered by the 'objectmaphelper' module.
import { RegularExpression, Wildcard } from 'objectmaphelper.js';

export var addressBookMainWindow = {"type": "MainWindow", "unnamed": 1, "visible": 1, "windowTitle": "Address Book"};
export var addressBookQMenuBar = {"type": "QMenuBar", "unnamed": 1, "visible": 1, "window": addressBookMainWindow};
export var addressBookFileQMenu = {"title": "File", "type": "QMenu", "unnamed": 1, "visible": 1, "window": addressBookMainWindow};
export var qFileDialogQFileDialog = {"name": "QFileDialog", "type": "QFileDialog", "visible": 1};
export var qFileDialogSplitterQSplitter = {"name": "splitter", "type": "QSplitter", "visible": 1, "window": qFileDialogQFileDialog};
export var splitterFrameQFrame = {"container": qFileDialogSplitterQSplitter, "name": "frame", "type": "QFrame", "visible": 1};
export var frameStackedWidgetQStackedWidget = {"container": splitterFrameQFrame, "name": "stackedWidget", "type": "QStackedWidget", "visible": 1};
export var stackedWidgetTreeViewQTreeView = {"container": frameStackedWidgetQStackedWidget, "name": "treeView", "type": "QTreeView", "visible": 1};
export var addressBookMyAddressesAdrMainWindow = {"type": "MainWindow", "unnamed": 1, "visible": 1, "windowTitle": "Address Book - MyAddresses.adr"};
export var addressBookMyAddressesAdrFileQToolBar = {"type": "QToolBar", "unnamed": 1, "visible": 1, "window": addressBookMyAddressesAdrMainWindow, "windowTitle": "File"};
export var addressBookMyAddressesAdrFileQTableWidget = {"aboveWidget": addressBookMyAddressesAdrFileQToolBar, "type": "QTableWidget", "unnamed": 1, "visible": 1, "window": addressBookMyAddressesAdrMainWindow};
export var fileLineEdit = {"columnIndex": 1, "container": addressBookMyAddressesAdrFileQTableWidget, "rowIndex": 3, "type": "LineEdit", "unnamed": 1, "visible": 1};
export var addressBookMyAddressesAdrAddQToolButton = {"text": "Add", "type": "QToolButton", "unnamed": 1, "visible": 1, "window": addressBookMyAddressesAdrMainWindow};
export var addressBookAddDialog = {"type": "Dialog", "unnamed": 1, "visible": 1, "windowTitle": "Address Book - Add"};
export var addressBookAddForenameQLabel = {"text": "Forename:", "type": "QLabel", "unnamed": 1, "visible": 1, "window": addressBookAddDialog};
export var forenameLineEdit = {"buddy": addressBookAddForenameQLabel, "type": "LineEdit", "unnamed": 1, "visible": 1};
export var addressBookAddSurnameQLabel = {"text": "Surname:", "type": "QLabel", "unnamed": 1, "visible": 1, "window": addressBookAddDialog};
export var surnameLineEdit = {"buddy": addressBookAddSurnameQLabel, "type": "LineEdit", "unnamed": 1, "visible": 1};
export var addressBookAddEmailQLabel = {"text": "Email:", "type": "QLabel", "unnamed": 1, "visible": 1, "window": addressBookAddDialog};
export var emailLineEdit = {"buddy": addressBookAddEmailQLabel, "type": "LineEdit", "unnamed": 1, "visible": 1};
export var addressBookAddPhoneQLabel = {"text": "Phone:", "type": "QLabel", "unnamed": 1, "visible": 1, "window": addressBookAddDialog};
export var phoneLineEdit = {"buddy": addressBookAddPhoneQLabel, "type": "LineEdit", "unnamed": 1, "visible": 1};
export var addressBookAddOKQPushButton = {"text": "OK", "type": "QPushButton", "unnamed": 1, "visible": 1, "window": addressBookAddDialog};
export var file33QModelIndex = {"column": 3, "container": addressBookMyAddressesAdrFileQTableWidget, "row": 3, "type": "QModelIndex"};
export var file32QModelIndex = {"column": 2, "container": addressBookMyAddressesAdrFileQTableWidget, "row": 3, "type": "QModelIndex"};
export var file31QModelIndex = {"column": 1, "container": addressBookMyAddressesAdrFileQTableWidget, "row": 3, "type": "QModelIndex"};
export var file30QModelIndex = {"column": 0, "container": addressBookMyAddressesAdrFileQTableWidget, "row": 3, "type": "QModelIndex"};
export var addressBookMyAddressesAdrQMenuBar = {"type": "QMenuBar", "unnamed": 1, "visible": 1, "window": addressBookMyAddressesAdrMainWindow};
export var addressBookMyAddressesAdrFileQMenu = {"title": "File", "type": "QMenu", "unnamed": 1, "visible": 1, "window": addressBookMyAddressesAdrMainWindow};
export var addressBookQMessageBox = {"type": "QMessageBox", "unnamed": 1, "visible": 1};
export var addressBookNoQPushButton = {"text": "No", "type": "QPushButton", "unnamed": 1, "visible": 1, "window": addressBookQMessageBox};
export var addressBookYesQPushButton = {"text": "Yes", "type": "QPushButton", "unnamed": 1, "visible": 1, "window": addressBookQMessageBox};
export var addressBookMyAddressesAdrRemoveQToolButton = {"text": "Remove", "type": "QToolButton", "unnamed": 1, "visible": 1, "window": addressBookMyAddressesAdrMainWindow};
export var qFileDialogDetailModeButtonQToolButton = {"name": "detailModeButton", "type": "QToolButton", "visible": 1, "window": qFileDialogQFileDialog};
export var addressBookChooseFileQFileDialog = {"name": "QFileDialog", "type": "QFileDialog", "visible": 1, "windowTitle": "Address Book - Choose File"};
export var addressBookChooseFileFileNameQLabel = {"name": "fileNameLabel", "text": "File name:", "type": "QLabel", "visible": 1, "window": addressBookChooseFileQFileDialog};
export var addressBookChooseFileOpenQPushButton = {"text": "Open", "type": "QPushButton", "unnamed": 1, "visible": 1, "window": addressBookChooseFileQFileDialog};
export var addressBookChooseFileDetailModeButtonQToolButton = {"name": "detailModeButton", "type": "QToolButton", "visible": 1, "window": addressBookChooseFileQFileDialog};
export var addressBookChooseFileLookInComboQComboBox = {"name": "lookInCombo", "type": "QComboBox", "visible": 1, "window": addressBookChooseFileQFileDialog};
export var addressBookChooseFileSplitterQSplitter = {"name": "splitter", "type": "QSplitter", "visible": 1, "window": addressBookChooseFileQFileDialog};
export var addressBookMyAddressesAdrEditQMenu = {"title": "Edit", "type": "QMenu", "unnamed": 1, "visible": 1, "window": addressBookMyAddressesAdrMainWindow};
export var addressBookMyAddressesAdr31LineEdit = {"column": 1, "row": 3, "type": "LineEdit", "unnamed": 1, "visible": 1, "window": addressBookMyAddressesAdrMainWindow};
export var file03QModelIndex = {"column": 3, "container": addressBookMyAddressesAdrFileQTableWidget, "row": 0, "type": "QModelIndex"};
export var file02QModelIndex = {"column": 2, "container": addressBookMyAddressesAdrFileQTableWidget, "row": 0, "type": "QModelIndex"};
export var file01QModelIndex = {"column": 1, "container": addressBookMyAddressesAdrFileQTableWidget, "row": 0, "type": "QModelIndex"};
export var file00QModelIndex = {"column": 0, "container": addressBookMyAddressesAdrFileQTableWidget, "row": 0, "type": "QModelIndex"};
