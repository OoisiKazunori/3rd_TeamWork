#pragma once

//+,+=,-,-=éûÇÃêÆêîÅAè≠êîÇÃåvéZñ¢äÆê¨
template<typename T>
struct Vector2 {

	T x;
	T y;

	Vector2<T> operator+(const Vector2<T> &obj)const {

		return Vector2<T>{ this->x + obj.x, this->y + obj.y };
	
	}
	Vector2<T> operator+=(const Vector2<T> &obj) {

		*this = *this + obj;
		return *this;

	}
	//Vector2<T> operator+(float obj)const {

	//	Vector2 tmp;

	//	tmp.x = x + obj.x;
	//	tmp.y = y + obj.y;

	//	return  tmp;
	//
	//}
	//Vector2<T> operator+=(const float &obj) {

	//	x += obj.x;
	//	y += obj.y;

	//	return *this;
	//
	//}


	Vector2<T> operator-(const Vector2<T> &obj)const {

		return Vector2<T>{this->x - obj.x, this->y - obj.y};
	
	}
	Vector2<T> operator-=(const Vector2<T> &obj) {

		*this = *this - obj;
		return *this;

	}
	//Vector2<T> operator-(const float &obj)const {

	//	Vector2 tmp;

	//	tmp.x = x - obj.x;
	//	tmp.y = y - obj.y;

	//	return  tmp;

	//}
	//Vector2<T> operator-=(const float &obj) {

	//	x -= obj.x;
	//	y -= obj.y;

	//	return *this;

	//}


	Vector2<T> operator-()const {

		return Vector2<T>{-this->x, -this->y};
	
	}


	Vector2<T> operator*=(const float &num) {

		*this = *this * num;
		return *this;
	
	}
	Vector2<T> operator*=(const Vector2 &obj)  {

		x *= obj.x;
		y *= obj.y;

		return *this;
	
	}
	Vector2<T> operator*(const float &num)const {

		return Vector2<T>{this->x *num, this->y *num};
	
	}
	Vector2<T> operator*(const Vector2 &obj)const {

		return Vector2<T>{this->x *obj.x, this->y *obj.y};
	
	}


	Vector2<T> operator/=(const float &num) {

		*this = *this / num;
		return *this;

	}
	Vector2<T> operator/=(const Vector2 &obj) {

		x /= obj.x;
		y /= obj.y;
		return *this;
	
	}
	Vector2<T> operator/(const float &num)const {

		return Vector2<T>{this->x / num, this->y / num};
	
	}
	Vector2<T> operator/(const Vector2 &obj)const {

		return Vector2<T>{this->x / obj.x, this->y / obj.y};
	
	}



	bool operator==(const Vector2<T> &obj)const {

		return (this->x == obj.x && this->y == obj.y);
	
	}
	bool operator==(const float &obj)const {

		return (this->x == obj.x && this->y == obj.y);
	
	}



	bool operator!=(const Vector2<T> &obj)const {

		return (this->x != obj.x && this->y != obj.y);
	
	}
	bool operator!=(const float &obj)const {

		return (this->x != obj.x && this->y != obj.y);
	
	}
};