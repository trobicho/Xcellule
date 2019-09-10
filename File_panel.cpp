/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File_panel.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:23:34 by trobicho          #+#    #+#             */
/*   Updated: 2019/09/10 21:03:12 by trobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File_panel.h"

File_panel::File_panel()
{
	m_fs_model.setRootPath("/Volumes/Storage/goinfre/trobicho/jslife");
	QTreeView tree;
	tree.setModel(&m_fs_model);
	tree.setAnimated(false);
	tree.setIndentation(20);
	tree.setSortingEnabled(true);
	const QSize availableSize = QApplication::desktop()->availableGeometry(&tree).size();
	tree.resize(availableSize / 2);
	tree.setColumnWidth(0, tree.width() / 3);

	tree.setWindowTitle(QObject::tr("Dir View"));
}
