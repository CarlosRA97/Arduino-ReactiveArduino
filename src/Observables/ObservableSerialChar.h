/***************************************************
Copyright (c) 2019 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
 ****************************************************/

#ifndef _REACTIVEOBSERVABLESERIALCHAR_h
#define _REACTIVEOBSERVABLESERIALCHAR_h

template <typename T>
class ObservableSerialChar : public Observable<T>
{
public:
	ObservableSerialChar();
	void Suscribe(IObserver<T> &observer);
	void Recieve();

private:
	IObserver<T>* _childObserver;
};

template <typename T>
inline ObservableSerialChar<T>::ObservableSerialChar()
{
}

template <typename T>
void ObservableSerialChar<T>::Suscribe(IObserver<T> &observer)
{
	_childObserver = &observer;
}

template <typename T>
void ObservableSerialChar<T>::Recieve()
{
	if (Serial.available())
	{
		char newChar = Serial.read();
		if (_childObserver != nullptr) _childObserver->OnNext(newChar);
	}
}

#endif