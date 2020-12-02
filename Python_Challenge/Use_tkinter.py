import tkinter

# 셍성 구문 - 위젯 구문 - 반복 구문
window_example = tkinter.Tk()  # 윈도우 창 생성

window_example.title("Example")  # 창의 제목
window_example.geometry("640x400+100+100")  # "너비x높이+x좌표+y좌표" 형식으로 너비,봎이,x,y좌표 설정
window_example.resizable(False, False)  # 창 크기 조절 여부 (상하, 좌우), 상수적용 가능

label_example = tkinter.Label(window_example, text="안녕하세요.")  # 위젯 설정
label_example.pack()  # 설정한 위젯 배치

window_example.mainloop()  # 윈도우창을 윈도우가 종료될때까지 실행


"""
12.7, (PC_이름_주제), Python관련 모든 것 이론 및 시연 예시, 5분- ppt,시연
"""
