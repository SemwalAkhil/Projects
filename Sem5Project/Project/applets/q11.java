//  Create an applet in Java to change the background color.

import java.applet.*;
import java.awt.*;
import java.awt.event.*;

/*
<applet code="ColorChangeApplet" width="400" height="300"></applet>
*/

public class ColorChangeApplet extends Applet implements ActionListener {
    Button redButton, greenButton, blueButton, yellowButton;

    public void init() {
        redButton = new Button("Red");
        greenButton = new Button("Green");
        blueButton = new Button("Blue");
        yellowButton = new Button("Yellow");
        add(redButton);
        add(greenButton);
        add(blueButton);
        add(yellowButton);
        redButton.addActionListener(this);
        greenButton.addActionListener(this);
        blueButton.addActionListener(this);
        yellowButton.addActionListener(this);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == redButton)
            setBackground(Color.red);
        else if (e.getSource() == greenButton)
            setBackground(Color.green);
        else if (e.getSource() == blueButton)
            setBackground(Color.blue);
        else if (e.getSource() == yellowButton)
            setBackground(Color.yellow);

        repaint();
    }
}


