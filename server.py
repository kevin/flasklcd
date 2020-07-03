from flask import Flask, render_template, request
from serial import Serial

app = Flask(__name__)

arduino = Serial('COM3', 9600, timeout=0.1)

@app.route('/', methods=['GET', 'POST'])
def form():
    return render_template('form.html')

@app.route('/send', methods=['GET', 'POST'])
def send():
    topInput = request.form['top']
    bottomInput = request.form['bottom']
    arduino.write((topInput + 'bottom:' + bottomInput).encode('UTF-8'))
    return render_template('sent.html', top=topInput, bottom=bottomInput)

if __name__ == "__main__":
    app.run()
