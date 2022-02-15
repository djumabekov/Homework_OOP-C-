//
// Menu.h
//
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <conio.h>  // _getch(), _kbhit()
#include "Win10.h"
using namespace std;

// структура для хранения компонентов консольных цветов
struct MColor {
    int Fon, Sym; // цвета фон и символа
};

class CMenu {
private:
    vector<string>  m_vItems;    // строки пунктов меню
    int             m_nSelect;   // индекс активного пункта меню
    int             m_nRow, m_nCol; // экран. коорд. меню
    // переменные для цветов вывода меню
    MColor m_colSel;     // цвет для активного пункта меню
    MColor m_colUnSel;   // цвет для неактивных пунктов меню
    MColor m_colDefault; // цвет по умолчанию (0,7)
public:
    void Set(const vector<string>& mItems) { m_vItems = mItems; }
    void AddItem(string& mItems) { this->m_vItems.push_back(mItems); }
    void SetSelect(int m_nSelect) { this->m_nSelect = m_nSelect; }
    void SetRow(int row) { this->m_nRow = m_nRow; }
    void SetCol(int col) { this->m_nCol = m_nCol; }
    void SetColSel(MColor m_colSel) { this->m_colSel = m_colSel; }
    void SetColUnSel(MColor m_colUnSel) { this->m_colUnSel = m_colUnSel; }
    void SetColDefault(MColor m_colDefault) { this->m_colDefault = m_colDefault; }

    string GetItem(int i) { return this->m_vItems.at(i); }
    int GetSelect() { return this->m_nSelect; }
    int GetRow() { return this->m_nRow; }
    int GetCol() { return this->m_nCol; }
    MColor GetColSel() { return this->m_colSel; }
    MColor GetColUnSel() { return  this->m_colUnSel; }
    MColor GetColDefault() { return this->m_colDefault; }

    CMenu() : m_vItems(), m_nSelect(), m_nRow(2), m_nCol(5),
        m_colSel({ COLOR::_BLUE, COLOR::_BRIGHT_WHITE }),
        m_colUnSel({ COLOR::_BLACK, COLOR::_YELLOW }),
        m_colDefault({ COLOR::_BLACK, COLOR::_WHITE })
    {}
    CMenu(const vector<string>& mItems) : CMenu() {
        Set(mItems);
    }
    CMenu(int row, int col) : CMenu() {
        m_nRow = row, m_nCol = col;
    }

    // вывести меню на экран
    int Show(int select = 0) {
        m_nSelect = select;
        while (true) {
            // 1) печать пунктов меню на экран
            int row = m_nRow;
            for (auto item : m_vItems) {
                if (m_nSelect == row - m_nRow) {
                    // цвет для активного пункта меню
                    SetColor(m_colSel.Fon, m_colSel.Sym);
                }
                else { // цвет для неактивных пунктов меню
                    SetColor(m_colUnSel.Fon, m_colUnSel.Sym);
                }
                SetPos(row++, m_nCol);
                cout << item;
            } // for (auto item : m_vItems)
            // восстанвливаем цвет консоли по умолчанию
            SetColor(m_colDefault.Fon, m_colDefault.Sym);
            // 2)
            int key = _getch();
            switch (key) {
            case KEY::UP: case KEY::LEFT: case 'w': case 'a': // верх
                if (m_nSelect > 0) { m_nSelect--; }
                else { m_nSelect = m_vItems.size() - 1; }
                break;
            case KEY::DOWN: case KEY::RIGHT: case 's': case 'd': // вниз
                if (m_nSelect < m_vItems.size() - 1) { m_nSelect++; }
                else { m_nSelect = 0; }
                break;
            case KEY::ENTER: return m_nSelect; // возвращаем индекс выбранного пункта меню
            case KEY::ESC:   return -1; // отказ от выбора
            }
        } // while(true);
    } // int Show()

    // вывести меню на экран
    int Show(int row, int col, int select = 0) {
        m_nRow = row;
        m_nCol = col;
        return Show(select);
    }
}; // class CMenu;

