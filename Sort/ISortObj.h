#pragma once
class ISortObj
{
public:
	ISortObj();
	virtual ~ISortObj();
	virtual bool LT(ISortObj *pObj) = 0;
	//virtual bool LE(ISortObj* pObj) = 0;
	virtual bool GT(ISortObj* pObj) = 0;
	//virtual bool GE(ISortObj* pObj) = 0;
	//virtual bool EQ(ISortObj* pObj) = 0;

	virtual void PrintObj() = 0;
	inline void SetIndexOri(int index) {
		this->_index_ori = index;
	}
	inline auto GetIndexOri() const {
		return this->_index_ori;
	}
private:
	int _index_ori;
};

