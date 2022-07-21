#include<simplecpp>

main_program{
    initCanvas("Carrom", 600 ,600);
    Rectangle outerBorder(300,300,500,500), innerBorder(300,300,440,440), shadowL(85,300,10,440), shadowR(555,308,10,500), shadowU(300,85,440,10), shadowD(308,555,500,10);
    Circle hole1(100,100,20), hole2(500,100,20), hole3(100,500,20), hole4(500,500,20), center(300,300,50);
    Rectangle outerBorderB(300,300,500,500), innerBorderB(300,300,440,440), launcher1(300,460,280,25), launcher2(460,300,25,280), launcher3(300,140,280,25), launcher4(140,300,25,280);
    outerBorder.setColor(COLOR(100,80,50));
    innerBorder.setColor(COLOR(250,200,90));
    hole1.setFill(); hole2.setFill(); hole3.setFill(); hole4.setFill();
    outerBorder.setFill(); innerBorder.setFill();

    shadowL.setColor(COLOR(200,170,65));
    shadowR.setColor(COLOR(180,180,180));
    shadowD.setColor(COLOR(180,180,180));
    shadowU.setColor(COLOR(200,170,65));
    shadowL.setFill(); shadowR.setFill(); shadowD.setFill(); shadowU.setFill();
    while(true){
        float ans=0, pos, ang=0, v=20, x,y;

        Circle strikerS(302, 462, 15), striker(300, 460, 15), strikerB(300, 460, 15);
        striker.setColor(COLOR(230,20,50));
        strikerS.setColor(COLOR(200,170,65));
        strikerS.setFill();
        striker.setFill();

        Line l(287,460,313,460);


        while (ans==0){
            cout << endl<< "type: \n 1 to move striker \n 2 to change launch angle \n 3 to launch \n 4 to exit"<<endl<<endl;
            cin >> ans;
            if(ans==1){
                cout <<endl<< "type a number from 0 to 100 \n(0=leftmost; 100=rightmost)"<<endl<<endl;
                cin >> pos;
                if((pos>=0)&&(pos<=100)){
                    strikerS.moveTo(162+280*pos/100,462); striker.moveTo(160+280*pos/100,460); strikerB.moveTo(160+280*pos/100,460); l.moveTo(160+280*pos/100,460);
                }
                ans=0;
            }
            else if(ans==2){
                striker.right(ang);
                strikerS.right(ang);
                strikerB.right(ang);
                l.right(ang);
                cout <<endl<< "type a number from 0 to 360 \n(ie., angle in degrees; 0 is right and angle is measured counter clockwise)"<<endl<<endl;
                cin >> ang;
                striker.left(ang);
                strikerS.left(ang);
                strikerB.left(ang);
                l.left(ang);
                ans=0;
            }
            else if(ans==4){break;}
            else if(ans!=3){ans=0;}
        }
        if(ans==4){break;}
        l.hide();
        while(true){
            striker.forward(v);
            strikerB.forward(v);
            strikerS.forward(v);
            x=striker.getX();
            y=striker.getY();
            if((x>499)||(x<101)){
                striker.left(180-2*ang);
                strikerB.left(180-2*ang);
                strikerS.left(180-2*ang);
                ang=180-ang;


            }
            if((y>499)||(y<101)){
                striker.right(2*ang-360);
                strikerB.right(2*ang-360);
                strikerS.right(2*ang-360);
                ang=360-ang;

            }

            if ( (((x-100)*(x-100)+(y-100)*(y-100))<380)|| (((x-100)*(x-100)+(y-500)*(y-500))<380)|| (((x-500)*(x-500)+(y-100)*(y-100))<380)||(((x-500)*(x-500)+(y-500)*(y-500))<380) ){
                strikerS.hide();
                striker.hide();
                strikerB.hide();
                break;
            }
            if ( (((x-100)*(x-100)+(y-100)*(y-100))<400)|| (((x-100)*(x-100)+(y-500)*(y-500))<400)|| (((x-500)*(x-500)+(y-100)*(y-100))<400)||(((x-500)*(x-500)+(y-500)*(y-500))<400) ){
                strikerS.hide();
            }else{
                strikerS.show();
            }

            wait(0.0001);
        }

        char yn='a';
        while(yn=='a'){
            cout << endl<< "GAME OVER \nWould you like to play again? (say \"y\" or \"n\")"<< endl;
            cin >> yn;
            if ((yn!='y')&&(yn!='n')){
                yn='a';
            }
        }
        if (yn=='n'){break;}
    }
}
