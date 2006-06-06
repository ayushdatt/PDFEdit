/* === Dialog helper functions === */

/** 
 * Create LineEdit dialog with label and text filled. 
 */
function createLineEdit(label,text) {
 e = new LineEdit;
 e.label = label;
 e.text = text;
 return e;
}

/** 
 * Create LineEdit dialog with label and text filled and add it 
 * to another widget.
 */
function createLineEditAndDisplay(label,text,widget) {
 e = new LineEdit;
 e.label = label;
 e.text = text;
 widget.add(e);
 return e;
}

/**
 * Create group box with title and tooltip the same.
 */
function createGroupBox(title) {
 gb = new GroupBox;
 gb.title = title;
 gb.tooltip = title;
 return gb;
}

/**
 * Create group box with title and tooltip the same.
 */
function createGroupBoxAndDisplay(title,widget) {
 gb = new GroupBox;
 gb.title = title;
 gb.tooltip = title;
 widget.add(gb);
 return gb;
}

/**
 * Create normal dialog
 */
function createDialog(caption, okButtonText, cancelButtonText, tooltip) {
 dialog = new Dialog;
 dialog.caption = caption;
 dialog.okButtonText = okButtonText;
 dialog.cancelButtonText = cancelButtonText;
 dialog.tooltip = tooltip;
 return dialog;
}

/**
 * Create spin box with max and min values and display it
 */
 function createSpinboxAndDisplay (label,min,max,widget) {
  sb = new SpinBox;
  sb.label = label;
  sb.minimum = min;
  sb.maximum = max;
  sb.tooltip = label;
  sb.whatsThis = label;
  widget.add (sb);
  return sb;
 }

/**
 * Create number edit box with max and min values and display it
 */
 function createNumbereditAndDisplay (label,min,max,widget) {
  sb = new NumberEdit;
  sb.label = label;
  sb.minimum = min;
  sb.maximum = max;
  sb.tooltip = label;
  sb.whatsThis = label;
  widget.add (sb);
  return sb;
 }

/**
 * Create radio button and display it
 */
function createRadioButtonAndDisplay (text,widget) {
 rb = new RadioButton;
 rb.text = text;
 rb.checked = false;
 rb.tooltip = text;
 widget.add (rb);
 return rb;
}

/**
 * Create check box and display it
 */
function createCheckBoxAndDisplay (text,widget) {
 cb = new CheckBox;
 cb.text = text;
 cb.checked = false;
 cb.tooltip = text;
 widget.add (cb);
 return cb;
}

/**
 * Make x,y edit boxes in a group box.
 */
function xydialogs (dg,text) {
	gb = createGroupBoxAndDisplay (text, dg);
	ex = createLineEditAndDisplay ("x"+tr("position"), "0", gb);
	ey = createLineEditAndDisplay ("y"+tr("position"), "0", gb);
	return [ex,ey];
}

/**
 * Make two number edit boxes in a group box.
 */
function twonumdialogs (dg,text,t1,t2) {
	gb = createGroupBoxAndDisplay (text, dg);
	ex = createLineEditAndDisplay (t1, "0", gb);
	ey = createLineEditAndDisplay (t2, "0", gb);
	return [ex,ey];
}