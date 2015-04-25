<?xml version="1.0" encoding="UTF-8"?>
<interface>
  <requires lib="gtk+" version="2.14"/>
  <!-- interface-naming-policy project-wide -->
  <object class="GtkListStore" id="datastore">
    <columns>
      <!-- column-name S No -->
      <column type="gchararray"/>
      <!-- column-name Protocol -->
      <column type="gchararray"/>
      <!-- column-name From -->
      <column type="gchararray"/>
      <!-- column-name To -->
      <column type="gchararray"/>
      <!-- column-name Src -->
      <column type="gchararray"/>
      <!-- column-name Dest -->
      <column type="gchararray"/>
    </columns>
    <data>
      <row>
        <col id="0" translatable="yes">1</col>
        <col id="1" translatable="yes">124</col>
        <col id="2" translatable="yes">fasdf</col>
        <col id="3" translatable="yes">asdf</col>
        <col id="4" translatable="yes">asdfdsaf</col>
        <col id="5" translatable="yes">asdfsdaf</col>
      </row>
    </data>
  </object>
  <object class="GtkWindow" id="window1">
    <property name="can_focus">False</property>
    <signal name="destroy" handler="gtk_main_quit" swapped="no"/>
    <child>
      <object class="GtkVBox" id="vbox1">
        <property name="visible">True</property>
        <property name="can_focus">False</property>
        <child>
          <object class="GtkTreeView" id="treeview">
            <property name="visible">True</property>
            <property name="can_focus">True</property>
            <child>
              <object class="GtkTreeViewColumn" id="imgcol">
                <property name="title">Image</property>
                <child>
                  <object class="GtkCellRendererPixbuf" id="imgcell"/>
                  <attributes>
                    <attribute name="stock-id">0</attribute>
                  </attributes>
                </child>
                <child>
                  <object class="GtkCellRendererText" id="namecell"/>
                  <attributes>
                    <attribute name="text">0</attribute>
                  </attributes>
                </child>
              </object>
            </child>
            <child>
              <object class="GtkTreeViewColumn" id="progresscol">
                <property name="title">Penetration</property>
                <child>
                  <object class="GtkCellRendererProgress" id="progresscell"/>
                  <attributes>
                    <attribute name="value">1</attribute>
                  </attributes>
                </child>
              </object>
            </child>
            <child>
              <object class="GtkTreeViewColumn" id="desccol">
                <property name="title">Description</property>
                <child>
                  <object class="GtkCellRendererText" id="desccell"/>
                  <attributes>
                    <attribute name="text">2</attribute>
                  </attributes>
                </child>
              </object>
            </child>
          </object>
          <packing>
            <property name="expand">True</property>
            <property name="fill">True</property>
            <property name="position">0</property>
          </packing>
        </child>
        <child>
          <object class="GtkFrame" id="frame1">
            <property name="visible">True</property>
            <property name="can_focus">False</property>
            <property name="label_xalign">0</property>
            <property name="shadow_type">none</property>
            <child>
              <object class="GtkTable" id="table1">
                <property name="visible">True</property>
                <property name="can_focus">False</property>
                <property name="n_columns">2</property>
                <property name="column_spacing">6</property>
                <property name="row_spacing">6</property>
                <child>
                  <object class="GtkButton" id="move_up">
                    <property name="label">gtk-go-up</property>
                    <property name="visible">True</property>
                    <property name="can_focus">True</property>
                    <property name="receives_default">True</property>
                    <property name="use_action_appearance">False</property>
                    <property name="use_stock">True</property>
                    <signal name="clicked" handler="cb_move" swapped="no"/>
                  </object>
                </child>
                <child>
                  <object class="GtkButton" id="move_down">
                    <property name="label">gtk-go-down</property>
                    <property name="visible">True</property>
                    <property name="can_focus">True</property>
                    <property name="receives_default">True</property>
                    <property name="use_action_appearance">False</property>
                    <property name="use_stock">True</property>
                    <signal name="clicked" handler="cb_move" swapped="no"/>
                  </object>
                  <packing>
                    <property name="left_attach">1</property>
                    <property name="right_attach">2</property>
                  </packing>
                </child>
              </object>
            </child>
            <child type="label">
              <object class="GtkLabel" id="label1">
                <property name="visible">True</property>
                <property name="can_focus">False</property>
                <property name="label" translatable="yes">Controls</property>
                <property name="use_markup">True</property>
              </object>
            </child>
          </object>
          <packing>
            <property name="expand">False</property>
            <property name="fill">True</property>
            <property name="position">1</property>
          </packing>
        </child>
      </object>
    </child>
  </object>
</interface>
