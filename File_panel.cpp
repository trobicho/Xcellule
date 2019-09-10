/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File_panel.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:23:34 by trobicho          #+#    #+#             */
/*   Updated: 2019/09/10 23:08:24 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File_panel.h"
#include <QDebug>

File_panel::File_panel()
{
	m_fs_model.setRootPath("/Volumes/Storage/goinfre/trobicho/jslife");
	setModel(&m_fs_model);
	setRootIndex(m_fs_model.index(m_fs_model.rootPath()));
	setAnimated(false);
	setIndentation(20);
	setSortingEnabled(true);
	const QSize availableSize = QApplication::desktop()->availableGeometry(this).size();
	resize(availableSize / 2);
	setColumnWidth(0, this->width() / 3);

	setWindowTitle(QObject::tr("Dir View"));
}

/*
void File_panel::on_treeView_clicked(const QModelIndex &index)
{
	QString mPath =	m_fs_model.fileInfo(index).absoluteFilePath();
	std::cout << "test" << mPath << std::endl;
}
*/

void File_panel::activated(const QModelIndex &index)
{
	QString mPath =	m_fs_model.fileInfo(index).absoluteFilePath();
	qDebug(qPrintable(mPath));
}
