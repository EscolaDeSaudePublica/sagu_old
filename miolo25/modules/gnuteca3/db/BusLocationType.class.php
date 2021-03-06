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
 * @author Jonas C. Rosa [jonas_rosa@solis.coop.br]
 *
 * @version $Id$
 *
 * \b Maintainers \n
 * Eduardo Bonfandini   [eduardo@solis.coop.br]
 * Jamiel Spezia        [jamiel@solis.coop.br]
 *
 * @since
 * Class created on 02/08/2012
 *
 * */
class BusinessGnuteca3BusLocationType extends GBusiness
{

    public $nameS;
    public $locationTypeIdS;
    
    public $name;
    public $_name;
    public $locationTypeId;
    

    function __construct()
    {
        parent::__construct('basLocationType', 'locationTypeId', 
                'name'
        );
    }

    public function listLocationType($object = FALSE)
    {
        return $this->autoList();
    }

    public function getLocationType($id)
    {
        $this->clear;
        $get = $this->autoGet($id);
        $this->_name = $this->name;
        
        return $get;
    }

    public function searchLocationType($toObject = false)
    {
        $filters = array(
            'locationTypeId' => 'equal',
            'name' => 'ilike'
        );

        $this->clear();

        return $this->autoSearch($filters, $toObject);
    }

    public function insertLocationType()
    {
        $this->name = $this->_name;
        return $this->autoInsert();
    }

    public function updateLocationType()
    {
        $this->name = $this->_name;
        return $this->autoUpdate();
    }

    public function deleteLocationType($locationTypeId)
    {
        return $this->autoDelete($locationTypeId);
    }

}

?>