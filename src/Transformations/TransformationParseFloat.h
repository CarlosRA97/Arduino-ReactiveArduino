/***************************************************
Copyright (c) 2019 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
 ****************************************************/

#ifndef _REACTIVETRANSFORMATIONPARSEFLOAT_h
#define _REACTIVETRANSFORMATIONPARSEFLOAT_h

template <typename Torig, typename Tdest>
class TransformationParseFloat : public Operator<Torig, Tdest>
{
public:
	TransformationParseFloat<Torig, Tdest>();

	void OnNext(Torig value);
};

template <typename Torig, typename Tdest>
TransformationParseFloat<Torig, Tdest>::TransformationParseFloat()
{
}

template<typename Torig, typename Tdest>
inline void TransformationParseFloat<Torig, Tdest>::OnNext(Torig value)
{
	this->_childObserver->OnNext((value).toFloat());
}
#endif
