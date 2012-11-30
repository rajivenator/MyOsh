// Default empty project template
import bb.cascades 1.0

// creates one page with a label
Page {
    id: mainPage
    titleBar: TitleBar {
        id: mainTitleBar
        title: "MyOsh Blackberry Native JSON Read Write "
    }
    function nativeCall() {
                          cs.getJSON();
                      }
    Container {
        id: mainPageContainer
        layout: StackLayout {
        }
        Button {
            id: btngetDataFromServer
            text: "Load Data From Server"
            onClicked: {
                btngetDataFromServer.enabled=false;
                nativeCall();
                
            }
            layoutProperties: StackLayoutProperties {
            }
            horizontalAlignment: HorizontalAlignment.Center
            verticalAlignment: VerticalAlignment.Center
            objectName: "btngetDataFromServer"
        }
        TextArea {
            id: txtRawJson
            verticalAlignment: VerticalAlignment.Bottom
            inputMode: TextAreaInputMode.Chat
            objectName: "txtRawJson"
        }
    }
}
