<?php
/**
 * <--- Copyright 2005-2011 de Solis - Cooperativa de Soluções Livres Ltda. e
 * Univates - Centro Universitário.
 * 
 * Este arquivo é parte do programa Gnuteca.
 * 
 * O Gnuteca é um software livre; você pode redistribuí-lo e/ou modificá-lo
 * dentro dos termos da Licença Pública Geral GNU como publicada pela Fundação
 * do Software Livre (FSF); na versão 2 da Licença.
 * 
 * Este programa é distribuído na esperança que possa ser útil, mas SEM
 * NENHUMA GARANTIA; sem uma garantia implícita de ADEQUAÇÃO a qualquer MERCADO
 * ou APLICAÇÃO EM PARTICULAR. Veja a Licença Pública Geral GNU/GPL em
 * português para maiores detalhes.
 * 
 * Você deve ter recebido uma cópia da Licença Pública Geral GNU, sob o título
 * "LICENCA.txt", junto com este programa, se não, acesse o Portal do Software
 * Público Brasileiro no endereço www.softwarepublico.gov.br ou escreva para a
 * Fundação do Software Livre (FSF) Inc., 51 Franklin St, Fifth Floor, Boston,
 * MA 02110-1301, USA --->
 * 
 * Grid
 *
 * @author Moises Heberle [moises@solis.coop.br]
 *
 * @version $Id$
 *
 * \b Maintainers \n
 * Eduardo Bonfandini [eduardo@solis.coop.br]
 * Jamiel Spezia [jamiel@solis.coop.br]
 * Luiz Gregory Filho [luiz@solis.coop.br]
 * Moises Heberle [moises@solis.coop.br]
 *
 * @since
 * Class created on 19/02/2009
 *
 **/
class GrdMaterialPhysicalType extends GSearchGrid
{
    public function __construct($data)
    {
    	$MIOLO  = MIOLO::getInstance();
    	$module = MIOLO::getCurrentModule();
    	$action = MIOLO::getCurrentAction();

        $columns = array(
            new MGridColumn(_M('Código', $module),        MGrid::ALIGN_RIGHT,  null, null, true, null, true),
            new MGridColumn(_M('Descrição', $module), MGrid::ALIGN_LEFT,   null, null, true, null, true),
            new MGridColumn(_M('Observação', $module), MGrid::ALIGN_LEFT,   null, null, true, null, true)
        );

        parent::__construct($data, $columns);

        $args['materialPhysicalTypeId'] = '%0%';
        $args['function'] = 'update';
        $hrefUpdate = $MIOLO->getActionURL($module, $action, null, $args);
        $args['function'] = 'delete';
        $this->setIsScrollable();
        $this->addActionUpdate( $hrefUpdate );
        $this->addActionDelete( GUtil::getAjax('tbBtnDelete_click', $args) );
    }
}
?>
