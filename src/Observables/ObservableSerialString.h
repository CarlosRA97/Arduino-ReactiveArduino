/***************************************************
Copyright (c) 2019 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
 ****************************************************/

#ifndef _REACTIVEOBSERVABLESERIALSTRING_h
#define _REACTIVEOBSERVABLESERIALSTRING_h

template <typename T>
class ObservableSerialString : public Observable<T>
{
public:
	ObservableSerialString(char separator = '\n');
	void Suscribe(IObserver<T> &observer);
	void Recieve();

private:
	String _buffer = "";
	char _separator;
	IObserver<T>* _childObserver;
};

template <typename T>
inline ObservableSerialString<T>::ObservableSerialString(char separator)
{
	_separator = separator;
}

template <typename T>
void ObservableSerialString<T>::Suscribe(IObserver<T> &observer)
{
	_childObserver = &observer;
}

template <typename T>
void ObservableSerialString<T>::Recieve()
{
	while (Serial.available())
	{
		char newChar = Serial.read();
		if (newChar != _separator)
		{
			_buffer.concat(newChar);
		}
		else
		{
			if (_childObserver != nullptr) _childObserver->OnNext(_buffer);
			_buffer = "";
		}
	}
}

#endif